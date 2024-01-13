#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class FileInfo
{
public:
    std::string head_name = "";
    int number = -1;
    int input_index = -1;
    std::string full_name = "";
};

bool cmp(const FileInfo& a, const FileInfo& b)
{
    if (a.head_name == b.head_name)
    {
        if (a.number == b.number)
        {
            return a.input_index < b.input_index;
        }
        return a.number < b.number;
    }
    return a.head_name < b.head_name;
}

FileInfo GetFileClass(const std::string& _file)
{
    FileInfo result_value;
    int i = 0;
    for (; i < _file.size(); ++i)
    {
        if ('0' <= _file[i] && _file[i] <= '9')
        {
            break;
        }
        if ('A' <= _file[i] && _file[i] <= 'Z')
        {
            result_value.head_name += _file[i] + 32;
        }
        else
        {
            result_value.head_name += _file[i];
        }
    }

    int j = i;
    for (; j < _file.size(); ++j)
    {
        if ('0' <= _file[i] && _file[i] <= '9')
        {
            continue;
        }
        break;
    }
    result_value.number = std::stoi(_file.substr(i, j));
    return result_value;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    std::vector<FileInfo> files_info;

    for (int i = 0; i < files.size(); ++i)
    {
        FileInfo info = GetFileClass(files[i]);
        info.input_index = i;
        info.full_name = files[i];
        files_info.push_back(info);
    }

    std::sort(files_info.begin(), files_info.end(), cmp);

    for (const FileInfo& _info : files_info)
    {
        answer.push_back(_info.full_name);
    }
    return answer;
}