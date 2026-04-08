#include <iostream>
#include <vector> 
#include <string>

using namespace std;

// 사용자의 데이터만 담는 구조체
struct User {
	string name; // 사용자 이름
	string tel; // 사용자 전화번호
};

// 직접 구현한 벡터 기능들
class MyVector {

public:
	// 생성자
	MyVector() {
		arr = new User[capacity];
	}

	// 소멸자
	~MyVector() {
		delete[] arr;
	}

	// 배열의 맨 끝에 데이터를 추가하는 함수
	void push_back(User value) {

		if (count == capacity) { // 만약 데이터가 배열의 크기와 같다면(용량이 꽉참을 의미함.)
			int newCapacity = capacity + 2; // 배열의 크기가 꽉 차면 +2씩 늘리기 위한 인스턴스.
			User* newArr = new User[newCapacity]; // 새로운 배열 선언.

			for (int i = 0; i < capacity; i++) {
				newArr[i] = arr[i]; // 새롭게 생성된 배열에 기존 배열의 데이터를 복사함.
			}

			delete[] arr; // 할당 해제
			arr = newArr; // 주소를 다시 지정함.
			capacity = newCapacity; // 배열의 크기 재설정.
		}

		arr[count] = value;
		count++;

	}

	// 배열의 데이터 갯수
	void size() {
		cout << count << endl;
	}

private:
	User* arr; // 배열 생성
	int count = 0; // 데이터 갯수
	int capacity = 2; // 배열의 (공간)크기
};

// 전화번호부 기능
class TelNumBook {
public:

	// 사용자 데이터 추가 함수
	void addContact(User newUser) {
		list.push_back(newUser);
	}

	// 전체 사용자 조회
	//void allUserList() {
	//	if (list.size() == 0) {
	//		cout << "데이터가 존재하지 않습니다." << endl;
	//	}

	//	for (int i = 0; i < list.size(); i++) {
	//		cout << "| 이름 | " << list[i].name << " | 전화번호 | " << list[i].tel << endl;
	//	}
	//}

	// 사용자 조회
	//void userSearch(string searchData) {

	//	bool isFound = false;
	//	vector<int> foundIndices;

	//	for (int i = 0; i < list.size(); i++) {
	//		if (list[i].name == searchData || list[i].tel == searchData) {
	//			foundIndices.push_back(i);
	//			cout << "[" << foundIndices.size() << "]" << "| 이름 | " << list[i].name << " | 전화번호 | " << list[i].tel << endl;
	//			isFound = true;
	//		}
	//	}
	//	cout << endl;

	//	while (isFound == true) {
	//		int subChoice;

	//		cout << "[1] 수정  [2] 삭제  [3] 이전으로" << endl;
	//		cout << "입력 : ";
	//		cin >> subChoice;

	//		if (subChoice == 1) {
	//			int inputNum;

	//			cout << "수정할 번호를 입력해주세요" << endl;
	//			cout << "NUMBER : ";
	//			cin >> inputNum;

	//			int realIndex = inputNum - 1;

	//			if (inputNum >= 1 && inputNum <= foundIndices.size()) {
	//				int targetAddress = foundIndices[realIndex];
	//				cout << "선택한 번호의 이름 : " << list[targetAddress].name << endl;
	//				cout << "선택한 번호의 전화번호 : " << list[targetAddress].tel << endl;

	//				cout << "변경할 이름 : ";
	//				cin >> list[targetAddress].name;
	//				cout << "변경할 전화번호 : ";
	//				cin >> list[targetAddress].tel;

	//				cout << "변경된 이름 : " << list[targetAddress].name << " | 변경된 전화번호 : " << list[targetAddress].tel << endl;
	//				break;
	//			}
	//		}

	//		if (subChoice == 2) {
	//			int inputNum;
	//			cout << "삭제할 번호를 입력해주세요" << endl;
	//			cout << "NUMBER : ";
	//			cin >> inputNum;

	//			int realIndex = inputNum - 1;

	//			if (inputNum >= 1 && inputNum <= foundIndices.size()) {
	//				int targetAddress = foundIndices[realIndex];
	//				list.erase(list.begin() + targetAddress);
	//				break;
	//			}
	//		}

	//		if (subChoice == 3) break;
	//	}

	//	if (isFound == false) {
	//		cout << "일치하는 데이터를 찾을 수 없습니다." << endl;
	//	}
	//}

private:
	MyVector list;
};

int main() {
	TelNumBook list;
	User user_struct;
	int menuChoice;

	while (true) {
		cout << "환영합니다. 이곳은 회원의 전화번호부를 관리하는 프로그램입니다." << endl;
		cout << "메뉴를 확인 후 입력칸에 입력해주세요!" << endl;
		cout << "  [1] 등록  [2] 조회  [3] 전체조회  [4] 프로그램 종료" << endl;
		cout << "입력 : ";
		cin >> menuChoice;
		cout << endl;
		cout << "[ ------------------------------------------------------ ]" << endl;

		if (menuChoice == 1) {
			cout << "NAME : ";
			cin >> user_struct.name;
			cout << "TEL : ";
			cin >> user_struct.tel;

			cout << user_struct.name << endl;
			cout << user_struct.tel << endl;

			list.addContact(user_struct);
		}

		//if (menuChoice == 2) {
		//	string searchData;
		//	cout << "Search(Name or Tel) : ";
		//	cin >> searchData;
		//	cout << endl;

		//	list.userSearch(searchData);
		//}

		//if (menuChoice == 3) {
		//	list.allUserList();
		//}

		if (menuChoice == 4) break;
	}

	return 0;
}