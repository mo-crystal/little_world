#include "renderable_actor.h"

RenderableActor::~RenderableActor()
{
}

void RenderableActor::SetDefaultState(const std::string &s_name)
{
  default_state = s_name;
  now_state = s_name;
}

bool RenderableActor::StateChange(const std::string &s_name)
{
  if (States.find(s_name) != States.end())
  {
    now_state = s_name;
    nowframe = 0;
    return true;
  }
  return false;
}

void RenderableActor::InitStates(const std::string &path) {
    auto WStringToString = [](const std::wstring &wstr) {
        if (wstr.empty()) return std::string();
        int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
        std::string str(size_needed, 0);
        WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &str[0], size_needed, NULL, NULL);
        return str;
    };

    auto StringToWString = [](const std::string &str) {
        if (str.empty()) return std::wstring();
        int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
        std::wstring wstr(size_needed, 0);
        MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstr[0], size_needed);
        return wstr;
    };

    std::wstring wpath = StringToWString(path) + L"\\*";

    std::regex number_regex(R"(\d+)");
    auto extract_number = [number_regex](const std::string &filename) {
        std::smatch match;
        if (std::regex_search(filename, match, number_regex)) {
            return std::stoi(match.str());
        }
        return 0;
    };

    WIN32_FIND_DATAW findFileData;
    HANDLE hFind = FindFirstFileW(wpath.c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        std::cerr << "Invalid file handle. Error is " << GetLastError() << std::endl;
        return;
    }

    do {
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            std::wstring folder_name_wstr(findFileData.cFileName);
            if (folder_name_wstr == L"." || folder_name_wstr == L"..") continue;

            std::string folder_name = WStringToString(folder_name_wstr);
            std::wstring folder_path = StringToWString(path) + L"\\" + folder_name_wstr + L"\\*";
            WIN32_FIND_DATAW fileData;
            HANDLE hFileFind = FindFirstFileW(folder_path.c_str(), &fileData);

            if (hFileFind == INVALID_HANDLE_VALUE) continue;

            do {
                std::wstring file_name_wstr(fileData.cFileName);
                std::string extension = WStringToString(file_name_wstr.substr(file_name_wstr.find_last_of(L".") + 1));
                if (extension == "png" || extension == "jpg") {
                    States[folder_name].push_back(WStringToString(folder_path.substr(0, folder_path.size() - 1) + file_name_wstr));
                }
            } while (FindNextFileW(hFileFind, &fileData) != 0);
            FindClose(hFileFind);

            std::sort(States[folder_name].begin(), States[folder_name].end(),
                      [&](const std::string &a, const std::string &b) {
                          return extract_number(a.substr(a.find_last_of("\\") + 1)) <
                                 extract_number(b.substr(b.find_last_of("\\") + 1));
                      });
        }
    } while (FindNextFileW(hFind, &findFileData) != 0);
    FindClose(hFind);

    if (!States.empty()) {
        SetDefaultState(States.begin()->first);
    }
}

void RenderableActor::AddState(std::string name,std::string path) {
    auto WStringToString = [](const std::wstring &wstr) {
        if (wstr.empty()) return std::string();
        int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
        std::string str(size_needed, 0);
        WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &str[0], size_needed, NULL, NULL);
        return str;
    };

    auto StringToWString = [](const std::string &str) {
        if (str.empty()) return std::wstring();
        int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
        std::wstring wstr(size_needed, 0);
        MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstr[0], size_needed);
        return wstr;
    };

    std::regex number_regex(R"(\d+)");
    auto extract_number = [number_regex](const std::string &filename) {
        std::smatch match;
        if (std::regex_search(filename, match, number_regex)) {
            return std::stoi(match.str());
        }
        return 0;
    };

    std::wstring wpath = StringToWString(path) + L"\\*";

    WIN32_FIND_DATAW findFileData;
    HANDLE hFind = FindFirstFileW(wpath.c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        std::cerr << "Invalid file handle. Error is " << GetLastError() << std::endl;
        return;
    }

    std::vector<std::string> files;

    do {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            std::wstring file_name_wstr(findFileData.cFileName);
            std::string extension = WStringToString(file_name_wstr.substr(file_name_wstr.find_last_of(L".") + 1));
            if (extension == "png" || extension == "jpg") {
                files.push_back(WStringToString(StringToWString(path) + L"\\" + file_name_wstr));
            }
        }
    } while (FindNextFileW(hFind, &findFileData) != 0);
    FindClose(hFind);

    std::sort(files.begin(), files.end(),
              [&](const std::string &a, const std::string &b) {
                  return extract_number(a.substr(a.find_last_of("\\") + 1)) <
                         extract_number(b.substr(b.find_last_of("\\") + 1));
              });

    States[name] = files;
}

void RenderableActor::NextFrame()
{
  nowframe++;
  if (nowframe >= States[now_state].size())
  {
    nowframe = 0;
  }
}

render_data RenderableActor::GetRenderData()
{
  return render_data(this->GetLocation(), States[now_state][nowframe]);
}