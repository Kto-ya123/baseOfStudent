#include<map>
#include<string>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<iterator>
#include<iostream>
#include<algorithm>
#include<windows.h>
#include<dos.h>

using namespace std;

struct mystruct
{
	mystruct() {}
	int year;
	int num_gp;
	int score[4];
	double sr_ball;

	mystruct(int _year, int _num_gp, int fiz, int mat, int inf, int him) :
		year(_year), num_gp(_num_gp), score{ fiz, mat, inf, him }
	{
		sr_ball = static_cast<double>(fiz + mat + inf + him) / 4;
	}
};
template <typename T> void _error(T&);
void _outer(map<string, mystruct>&);
void _menu(map<string, mystruct>&);
void _del(map<string, mystruct>&);
void _kor(map<string, mystruct>& mp)
{
	string name;
	cout << "��� ������ �� ������ ��������?: ";
	getline(cin, name);
	if (name == "")
		getline(cin, name);
	if (mp.find(name) == mp.end())
	{
		cout << "����� ������� �� ������" << endl;
		system("pause");
		_menu(mp);
	}
	cout << "������� ��� ��������:";
	if (!(cin >> mp[name].year))
		_error(mp[name].year);
	cout << "������� ����� ������:";
	if (!(cin >> mp[name].num_gp))
		_error(mp[name].num_gp);
	cout << "������� ������ �� ������:";
	if (!(cin >> mp[name].score[0]))
		_error(mp[name].score[0]);
	cout << "������� ������ �� ����������:";
	if (!(cin >> mp[name].score[1]))
		_error(mp[name].score[1]);
	cout << "������� ������ �� �����������:";
	if (!(cin >> mp[name].score[2]))
		_error(mp[name].score[2]);
	cout << "������� ������ �� �����:";
	if (!(cin >> mp[name].score[3]))
		_error(mp[name].score[3]);
	mp[name].sr_ball = double(mp[name].score[0] + mp[name].score[1] + mp[name].score[2] + mp[name].score[3]) / 4;
	return;
}
void _outer(map<string, mystruct>& mp)
{
	system("cls");
	cout << "������� �����: ";
	char s;
	if (!(cin >> s))
		_error(s);
	auto beg = mp.begin();
	while (beg != mp.cend())
	{
		if ((*beg).first[0] == s && (*beg).second.sr_ball >= 9)
		{
			ostream_iterator<int> ot(cout, " ");
			cout << "\"" << (*beg).first << "\" ";
			cout << "��� ��������: ";
			ot = (*beg).second.year;
			cout << "����� ������: ";
			ot = (*beg).second.num_gp;
			cout << "������: ";
			ot = (*beg).second.score[0];
			cout << "����������: ";
			ot = (*beg).second.score[1];
			cout << "�����������: ";
			ot = (*beg).second.score[2];
			cout << "�����: ";
			ot = (*beg).second.score[3];
			cout << "������� ����: ";
			cout << (*beg).second.sr_ball;
			cout << endl;
		}
		beg++;
	}
	system("pause");
	return;
	
}
void in_file(map<string, mystruct>& mp)
{
	ifstream fin("file.txt", ifstream::in);
	string name;
	string str;
	while (!(fin.eof()) && fin.is_open())
	{
		while (1)
		{
			str = "";
			fin >> str;
			if (str == "")
				return;
			if (*(str.end() - 1) == '"')
			{
				name += str;
				name.erase(name.begin(), name.begin() + 1);
				name.erase(name.end() - 1, name.end());
				break;
			}
			name += str + " ";
		}
		mp[name];
		fin >> mp[name].year;
		fin >> mp[name].num_gp;
		fin >> mp[name].score[0];
		fin >> mp[name].score[1];
		fin >> mp[name].score[2];
		fin >> mp[name].score[3];
		fin >> mp[name].sr_ball;
		name = "";
	}
}
void out_file(map<string, mystruct>& mp)
{
	ofstream fout("file.txt", ofstream::out);
	/*	for (const auto& m : mp)
	{
	fout << m.first << " ";
	fout << " ��� ��������: ";
	fout << m.second.year;
	fout << " ����� ������: ";
	fout << m.second.num_gp;
	fout << " ������: ";
	fout << m.second.score[0];
	fout << " ����������: ";
	fout << m.second.score[1];
	fout << " �����������: ";
	fout << m.second.score[2];
	fout << " �����: ";
	fout << m.second.score[3];
	fout << " ������� ����: ";
	fout << m.second.sr_ball;
	fout << endl;
	}*/
	for (const auto& m : mp)
	{
		fout << "\"" << m.first << "\" ";
		fout << m.second.year << " ";
		fout << m.second.num_gp << " ";
		fout << m.second.score[0] << " ";
		fout << m.second.score[1] << " ";
		fout << m.second.score[2] << " ";
		fout << m.second.score[3] << " ";
		fout << m.second.sr_ball << " ";
		fout << endl;
	}
}
template <typename T> void _error(T& val)
{
	while (1)
	{
		cout << "������.��������� ����: ";
		cin.clear();
		if (cin >> val)
			break;

	}
}
void _add(map<string, mystruct>& mp)
{
	string name;
	int year = 0;
	int num_gp;
	int fiz;
	int mat;
	int inf;
	int him;
	cout << "������� ��� � ��������:";
	getline(cin, name);
	if (name == "")
		getline(cin, name);
	cout << "������� ��� ��������:";
	if (!(cin >> year))
		_error(year);
	cout << "������� ����� ������:";
	if (!(cin >> num_gp))
		_error(num_gp);
	cout << "������� ������ �� ������:";
	if (!(cin >> fiz))
		_error(fiz);
	cout << "������� ������ �� ����������:";
	if (!(cin >> mat))
		_error(mat);
	cout << "������� ������ �� �����������:";
	if (!(cin >> inf))
		_error(inf);
	cout << "������� ������ �� �����:";
	if (!(cin >> him))
		_error(him);
	mystruct uch(year, num_gp, fiz, mat, inf, him);
	mp[name] = uch;
	return;
}
void _del(map<string, mystruct>& mp)
{
	string name;
	cout << "��� ������ �� ������ �������?: ";
	getline(cin, name);
	if (name == "")
		getline(cin, name);
	if (mp.find(name) == mp.end())
	{
		cout << "����� ������� �� ������" << endl;
		system("pause");
		_menu(mp);
	}
	mp.erase(name);
	cout << "�������� ������ �������" << endl;
	system("pause");
	return;
}
void _out(map<string, mystruct>& mp)
{
	ostream_iterator<int> ot(cout, " ");
	for (const auto& m : mp)
	{
		cout << "\"" << left << setw(10)<< m.first << "\"";
		cout << "��� ��������: ";
		cout <<  m.second.year <<' ';
		cout << "����� ������: ";
		cout <<  m.second.num_gp <<' ';
		cout << "������: ";
		cout <<  m.second.score[0]<<' ';
		cout << "����������: ";
		cout << m.second.score[1] <<' ';
		cout << "�����������: ";
		cout << m.second.score[2] << ' ';
		cout << "�����: ";
		cout << m.second.score[3]<<' ';
		cout << "������� ����: ";
		cout << m.second.sr_ball;
		cout << endl;
		Sleep(50);
	}
	system("pause");
	return;
}
void _menu(map<string, mystruct>& mp)
{
	while (1)
	{
		system("cls");
		out_file(mp);
		cout << "0.������� ��������� ����������" << endl;
		cout << "1.���������� ��������" << endl;
		cout << "2.�������� ���������" << endl;
		cout << "3.�������� ������" << endl;
		cout << "4.���������" << endl;
		cout << "5.�����" << endl;

		cout << endl;
		int cs;
		do
		{
			cout << "��� �����: ";
			if (!(cin >> cs))
				_error(cs);
		} while (cs < 0 || cs > 5);
		switch (cs)
		{
		case 0: _outer(mp);
			break;
		case 1: _add(mp);
			break;
		case 2: _del(mp);
			break;
		case 3: _out(mp);
			break;
		case 4: _kor(mp);
			break;
		case 5: return;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	map<string, mystruct> mp;

	in_file(mp);
	_menu(mp);
	return 0;
}