/*
	通讯录是一个可以记录亲人、好友信息的工具。

	利用C++来实现一个通讯录管理系统

	系统中需要实现的功能如下：

	* 添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录10人
	* 显示联系人：显示通讯录中所有联系人信息
	* 删除联系人：按照姓名进行删除指定联系人
	* 查找联系人：按照姓名查看指定联系人信息
	* 修改联系人：按照姓名重新修改指定联系人
	* 清空联系人：清空通讯录中所有信息
	* 退出通讯录：退出当前使用的通讯录


*/


#include<iostream>
#define MAX 11




using namespace std;

//菜单展示函数  showMenu
void showMenu() {
	cout << "****************************" << endl;
	cout << "*****   1.添加联系人   *****" << endl;
	cout << "*****   2.显示联系人   *****" << endl;
	cout << "*****   3.删除联系人   *****" << endl;
	cout << "*****   4.查找联系人   *****" << endl;
	cout << "*****   5.修改联系人   *****" << endl;
	cout << "*****   6.清空联系人   *****" << endl;
	cout << "*****   0.退出通讯录   *****" << endl;
	cout << "****************************" << endl;
}

//联系人结构体 Person

struct Person {
	string name;      //联系人姓名
	string gender;    //联系人性别
	int age;          //联系人年龄
	string phone;     //联系人电话
	string address;   //联系人家庭住址
};

//通讯录结构体 Addressbooks
struct Addressbooks {
	struct Person personArray[MAX]; //通讯录中保存的联系人数组
	int size;         //通讯录中联系人个数
};


//添加联系人函数 addPreson
//添加联系人前判断通讯录是否已满,如果满了就不再添加,未满情况将新联系人信息逐个加入到通讯录


void addPerson(Addressbooks* abs) {

	if (abs->size == MAX - 1) {

		cout << "联系人已经超过通讯录最大容量,请清理空间后再添加! Σ( ° △ °|||)︴" << endl;
	}
	else
	{
		//添加姓名

		string name;
		cout << "请输入添加联系人的姓名" << endl;
		cin >> name;
		abs->personArray[abs->size].name = name;


		//添加性别

		cout << "请输入添加联系人的性别" << endl;
		cout << "0 -- 女" << endl;
		cout << "1 -- 男" << endl;

		int genderId = 0;

		while (true)
		{
			while (!(cin >> genderId) || cin.peek() != '\n')
			{
				cin.clear();	//清除错误标志
				cin.ignore(numeric_limits<streamsize>::max(), '\n');   //清空输入缓冲区,去除换行符
				cout << "输入数据格式错误,请重新输入:" << endl;
			}

			if (genderId == 0)
			{
				abs->personArray[abs->size].gender = "女";
				break;
			}
			else if (genderId == 1) {
				abs->personArray[abs->size].gender = "男";
				break;
			}
			else
			{
				cout << "输入错误,请重新输入!" << endl;
			}

		}

		//添加年龄

		int age{};
		cout << "请输入联系人年龄" << endl;
		while (true)
		{

			while (!(cin >> age) || cin.peek() != '\n')
			{
				cin.clear();	//清除错误标志
				cin.ignore(numeric_limits<streamsize>::max(), '\n');   //清空输入缓冲区,去除换行符
				cout << "输入数据格式错误,请重新输入:" << endl;
			}

			if (age > 0 && age <= 150)
			{
				abs->personArray[abs->size].age = age;
				break;
			}
			else {
				cout << "输入的年龄错误,请重新输入!" << endl;
			}
		}


		//添加联系人电话号码

		string phone{};

		cout << "请输入联系人电话号码" << endl;

		while (true)
		{
			cin >> phone;

			if (phone.length() == 11) {
				abs->personArray[abs->size].phone = phone;
				break;
			}
			else
			{
				cout << "输入的手机号有误,请重新输入!" << endl;
			}
		}

		//添加联系人所在地址

		string address{};
		cout << "请输入联系人所在地址" << endl;
		cin >> address;
		abs->personArray[abs->size].address = address;

		cout << "添加成功!  φ(゜▽゜*)♪" << endl;

		abs->size++;  //通讯录联系人数自增	
	}

	system("pause");
	system("cls");

}

//显示联系人函数 showPerson
//显示已经添加的联系人基本信息

void showPerson(Addressbooks* abs) {

	if (abs->size == 0)
	{
		cout << "显示联系人失败! 当前记录为空,请先添加联系人 Σ( ° △ °|||)︴" << endl;
	}
	else {
		cout << "-------------------------------------------------------------------------" << endl;

		cout << "\t姓名" << "\t性别" << "\t年龄" << "\t电话号码" << "\t家庭地址" << endl;


		for (int i = 0; i < abs->size; i++)
		{

			cout << "\t" << abs->personArray[i].name << "\t" << abs->personArray[i].gender << "\t" << abs->personArray[i].age << "\t" << abs->personArray[i].phone << "\t" << abs->personArray[i].address << endl;


		}

		cout << endl;

		cout << "通讯录目前已经添加(" << abs->size << "/" << MAX - 1 << ")位联系人" << endl;

		cout << "-------------------------------------------------------------------------" << endl;
	}

	


	system("pause");

	system("cls");

}

//判断联系人是否存在
//若存在,返回索引值
//若不存在,返回值-1;

int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personArray[i].name == name) {
			return i;
		}
	}
	return -1;
}

//删除联系人函数 deletePerson

void deletePerson(Addressbooks* abs) {

	if (abs->size == 0)
	{
		cout << "删除联系人失败! 当前记录为空,请先添加联系人 Σ( ° △ °|||)︴" << endl;
	}
	else
	{
		string name{};
		cout << "请输入要删除的联系人姓名" << endl;
		cin >> name;
		int ret = isExist(abs, name);

		if (ret != -1)
		{
			for (int i = ret; i < abs->size; i++)
			{
				abs->personArray[i] = abs->personArray[i + 1];

			}

			abs->size--;

			cout << "删除成功!" << endl;
		}
		else
		{
			cout << "查无此人,删除失败!" << endl;
		}

	}
	
	system("pause");
	system("cls");
}

//查找联系人函数 selectPerson

void selectPerson(Addressbooks* abs) {
	if (abs->size == 0)
	{
		cout << "查找联系人失败! 当前记录为空,请先添加联系人 Σ( ° △ °|||)︴" << endl;
	}
	else
	{
		string name{};
		cout << "请输入要查找的联系人姓名" << endl;
		cin >> name;
		int ret = isExist(abs, name);

		if (ret != -1)
		{
			cout << "根据姓名查找到以下内容↓" << endl;

			cout << "-------------------------------------------------------------------------" << endl;

			cout << "\t姓名" << "\t性别" << "\t年龄" << "\t电话号码" << "\t家庭地址" << endl;

			cout << "\t" << abs->personArray[ret].name << "\t" << abs->personArray[ret].gender << "\t" << abs->personArray[ret].age << "\t" << abs->personArray[ret].phone << "\t" << abs->personArray[ret].address << endl;

			cout << "-------------------------------------------------------------------------" << endl;

		}
		else
		{
			cout << "很抱歉,查无此人!" << endl;
		}
	}

	system("pause");
	system("cls");
}

//修改联系人 updatePerson

void updatePerson(Addressbooks* abs) {

	if (abs->size == 0)
	{
		cout << "修改联系人信息失败! 当前记录为空,请先添加联系人! Σ( ° △ °|||)︴" << endl;
	}
	else
	{
		string name{};
		cout << "请输入要修改信息的联系人姓名" << endl;
		cin >> name;
		int ret = isExist(abs, name);

		if (ret != -1)
		{
			int selectUpdId{};
			cout << "-------------------------------------------------------------------------" << endl;
			cout << "请输入数字选择要更改的信息" << endl;
			cout << "1---修改联系人姓名" << endl;
			cout << "2---修改联系人性别" << endl;
			cout << "3---修改联系人年龄" << endl;
			cout << "4---修改联系人电话号码" << endl;
			cout << "5---修改联系人所在地址" << endl;
			cout << "-------------------------------------------------------------------------" << endl;

			while (!(cin >> selectUpdId) || cin.peek() != '\n')
			{
				cin.clear();	//清除错误标志
				cin.ignore(numeric_limits<streamsize>::max(), '\n');   //清空输入缓冲区,去除换行符
				cout << "输入数据格式错误,请重新输入:" << endl;
			}

			switch (selectUpdId)
			{
			case 1:
				//修改联系人的姓名
			{
				string name;
				cout << "请输入修改联系人的姓名" << endl;
				cin >> name;
				abs->personArray[ret].name = name;
				cout << "修改成功! ヾ(≧▽≦*)o" << endl;
			}
			break;
			case 2:
				//更改联系人的性别
			{
				cout << "请选择更改联系人的性别" << endl;
				cout << "0 -- 女" << endl;
				cout << "1 -- 男" << endl;

				int genderId = 0;

				while (true)
				{
					cin >> genderId;

					if (genderId == 0)
					{
						abs->personArray[ret].gender = "女";
						cout << "修改成功! ヾ(≧▽≦*)o" << endl;
						break;
					}
					else if (genderId == 1) {
						abs->personArray[ret].gender = "男";
						cout << "修改成功! ヾ(≧▽≦*)o" << endl;
						break;
					}
					else
					{
						cout << "输入错误,请重新输入!" << endl;
					}

				}
			}

			break;
			case 3:
				//修改联系人年龄

			{
				int age{};
				cout << "请输入要修改的联系人年龄" << endl;
				while (true)
				{
					cin >> age;

					if (age > 0 && age <= 150)
					{
						abs->personArray[ret].age = age;
						cout << "修改成功! ヾ(≧▽≦*)o" << endl;
						break;
					}
					else {
						cout << "输入的年龄错误,请重新输入!" << endl;
					}
				}

			}

			break;
			case 4:
				//修改联系人电话号码
			{
				string phone{};

				cout << "请输入要修改的联系人电话号码" << endl;

				while (true)
				{
					cin >> phone;

					if (phone.length() == 11) {
						abs->personArray[ret].phone = phone;
						cout << "修改成功! ヾ(≧▽≦*)o" << endl;
						break;
					}
					else
					{
						cout << "输入的手机号有误,请重新输入!" << endl;
					}
				}

			}

			break;
			case 5:
				//修改联系人所在地址
			{
				string address{};
				cout << "请输入要修改的联系人所在地址" << endl;
				cin >> address;
				abs->personArray[ret].address = address;

				cout << "修改成功! ヾ(≧▽≦*)o" << endl;

			}

			break;
			default:
				cout << "输入有误,请重新输入!" << endl;

			}
		}
		else
		{
			cout << "很抱歉,查无此人!" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

//清空联系人 clearPerson

void clearPerson(Addressbooks* abs) {
	cout << "!! 注意,清空联系人不可找回,请确认是否清空" << endl;
	cout << "1------是,执行操作" << endl;
	cout << "2------否,我只是点错了" << endl;
	int ConfirmValue{};
	FLAG:
	while (!(cin >> ConfirmValue) || cin.peek() != '\n')
	{
		cin.clear();	//清除错误标志
		cin.ignore(numeric_limits<streamsize>::max(), '\n');   //清空输入缓冲区,去除换行符
		cout << "输入数据格式错误,请重新输入:" << endl;
	}

	if (ConfirmValue == 1)
	{
		abs->size = 0;
		cout << "通讯录已清空!" << endl;
	}
	else if(ConfirmValue == 2)
	{
		cout << "正在返回菜单,请稍后" << endl;
	}
	else
	{
		cout << "输入错误,请重新输入!" << endl;
		goto FLAG;
	}
	

	system("pause");
	system("cls");
}


int eventProcessing() {

	Addressbooks abs;

	abs.size = 0;

	while (true)
	{

		//菜单显示
		showMenu();

		int selectId{};
	
		// 检测输入的id是否为其他格式如字符串并提醒

		while (!(cin >> selectId) || cin.peek() != '\n')
		{
			cin.clear();	//清除错误标志
			cin.ignore(numeric_limits<streamsize>::max(), '\n');   //清空输入缓冲区,去除换行符
			cout << "输入数据格式错误,请重新输入:" << endl;
		}

		switch (selectId)
		{
		case 1:
			//添加联系人
			addPerson(&abs);
			break;
		case 2:
			//显示联系人
			showPerson(&abs);
			break;
		case 3:
			//删除联系人
			deletePerson(&abs);
			break;
		case 4:
			//查找联系人
			selectPerson(&abs);
			break;
		case 5:
			//修改联系人
			updatePerson(&abs);

			break;
		case 6:
			//清空联系人
			clearPerson(&abs);
			break;
		case 0:
			//退出通讯录
			cout << "/// 欢迎下次使用 ///" << endl;
			system("pause");
			return 0;
		default:
			cout << "输入有误,请重新输入!" << endl;
			system("pause");
			system("cls");
		}
	}

}




int main() {

	eventProcessing();

	return 0;
}