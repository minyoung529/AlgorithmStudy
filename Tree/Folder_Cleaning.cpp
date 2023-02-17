#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

struct file
{
	unordered_map<string, int> files;
	int fileCnt = 0;
};

unordered_map<string, file> fileMap;
unordered_map<string, vector<string>> folderTree;

unordered_map<string, int> files;
int cnt = 0;

void DFS(string folderName);

int main()
{
	int folder, file, question;
	cin >> folder >> file;

	for (int i = 0; i < folder + file; i++)
	{
		string parent, child;
		int type;

		cin >> parent >> child >> type;

		if (type == 0)	// 파일
		{
			fileMap[parent].files[child]++;
			fileMap[parent].fileCnt++;
		}
		else // 폴더
		{
			folderTree[parent].push_back(child);
		}
	}

	cin >> question;

	while (question--)
	{
		string path, folderName;
		cin >> path;

		int start = -1;
		cnt = 0;
		files.clear();

		for (int i = path.size(); i >= 0; i--)
		{
			if (path[i] == '/')
			{
				start = i;
				break;
			}
		}

		folderName = path.substr(start + 1, path.size() - start);
		DFS(folderName);

		cout << files.size() << ' ' << cnt << '\n';
	}
}

void DFS(string folderName)
{
	cnt += fileMap[folderName].fileCnt;

	for (auto pair : fileMap[folderName].files)
		files[pair.first]++;

	for (int i = 0; i < folderTree[folderName].size(); i++)
	{
		DFS(folderTree[folderName][i]);
	}
}
