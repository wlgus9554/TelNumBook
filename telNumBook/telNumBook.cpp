 // 전화번호부 프로젝트
#include <iostream>
#include <vector> // vector를 사용하기 위한 헤더 
using namespace std;

// 복잡한 기능 없이 데이터만 깔끔하게 묶어놓은 바구니.
// 개발자들 사이에선 
// struct를 쓸 때 : 이건 복잡한 기능 없이 데이터만 깔끔하게 묶어놓은 바구니야. 편하게 꺼내써! 라는 의도로 주로 사용함.
// class를 쓸 때 : 이건 데이터도 중요하지만, 그걸 다루는 복잡한 논리와 보안이 중요해. 정해진 함수로만 접근해! 라는 의도로 사용함.
struct User
{
	// struct에서 생성한 변수는 기본적으로 public(공용)으로 생성된다.
	// 하지만 struct도 private:으로 외부 접근을 막아서 은닉화 시킬 수 있다.

	// private: 
	// --> 주석한 이유 : struct를 모두가 접근 가능한 public 형태로 우선 생성한다.
	// class를 User(struct로 생성한 데이터 모음 바구니)들을 관리하는 시스템으로 만든다.
	// 	   private : User 객체들을 담아두는 배열이나, 벡터.(데이터가 꼬이지 않게 숨김.)
	// 	   public: addContact(), searchContact() 같은 함수들.(사용자가 쓰는 버튼 역할)
 
	// string -> C++ 표준 라이브러리에서 제공하는 클래스임.
	// 크기 : 글자 수에 맞춰 자동 조절
	// 비교 : == 연산자 사용 가능
	// 복사/대입 : = 연산자 사용 가능
	// 유연성 : 제한 없이 늘어남

	string name; // 이름
	string tel; // 전화번호
};

class TelNumBook
{
public:
	// 사용자의 정보를 입력하는 함수입니다.
	void addContact(User newUser) { // User 타입의 데이터를 newUser라는 이름으로 부름.
		// list[count] = newUser; // list[0](count의 초깃값이 0임) = newUser에 있는 데이터를 통째로 복사해서 넣는다. 
		// --> ★vector 사용으로 인해 주석처리한 코드★

		list.push_back(newUser); // 빈 자리가 있다면 가장 끝에 데이터를 복사해서 넣음.

		// push_back 이 하는 기능
		// 공간 확인 : " 지금 공간에 새로운 데이터를 넣을 빈 자리가 있는가? "
		// (★★★★★)데이터 안착 : "빈 자리가 있다면 가장 끝에 데이터를 복사해서 넣는다."
		// 내부 카운트 업데이트 : "데이터가 하나 늘었으니 내 크기(size)를 1 늘려야지. (기존 count++ 의 역할을 대신함)
		// 나중에 몇 명이 저장되어 있는지 궁금할때는
		// list.size() 함수를 호출한다. -> 현재 저장중인 데이터 수를 출력할 수 있음.
		
		// count++; // count를 1증가 시킴 --> ★vector 사용으로 인해 주석처리한 코드★
		// count를 1 증가 시키게 되면 다음 등록때는 list[1], 그 다음은 list[2] 이런식으로 데이터를 순차적으로 배열 안에 자동으로 복사해서 넣게 된다.

		cout << list.size() << endl; // size() 함수로 현재 저장된 데이터의 숫자를 출력함.

		// cout << count << endl; // count 증가 확인용 코드 --> ★vector 사용으로 인해 주석처리한 코드★
	}

	void allUserList() {

		// 만약 데이터가 존재하지 않을 경우 경고문 출력.
		if (list.size() == 0) {
			cout << "데이터가 존재하지 않습니다." << endl;
		}

		for (int i = 0; i < list.size(); i++) {
			cout << "| 이름 | " << list[i].name << " | 전화번호 | " << list[i].tel << endl;
		}
		// 해당 코드를 풀이하면 다음과 같음.
		// i = 0; i < list.size() -> 0부터 list.size()까지(데이터가 존재하는 만큼);
		// 출력한다. list[i] list의 i번째 배열에 담긴 name과 tel을 
		// Ex) list[0].name, list[0].tel -> 도르니, 010-1234-1234가 담겨져 있음.

	}

private:
	//User list[100]; // User는 struct로 만든 데이터 바구니이다. 이를 list라는 이름으로 배열 형태의 [100] 크기, 0~99까지로 생성한다. --> ★vector 사용으로 인해 주석처리한 코드★

	vector<User> list; // vector를 사용하여 정해진 배열의 크기가 아닌 동적으로 배열을 관리하게 설계함.

	// 기존 배열 방식에서는 배열(list)이 그냥 공간일 뿐이라서, 현재 어디까지 찼는지 알려주는 손가락(count)이 필요했음. 하지만 vector는 공간 + 관리자 가 합쳐진 클래스임.
	// - 배열 방식(기존 하려했던 방식) : 0번째 칸에 넣고, 이제 1번이라고 표시해둬(수동)
	// -vector방식 : push_back해 -> vector 내부에서 "지금 0번까지 찼네? 그럼 1번에 넣고 내가 기억해둬야지."(자동)

	// int count = 0; // 현재 저장된 인원수 체크용 --> ★vector 사용으로 인해 주석처리한 코드★
};

int main()
{
	TelNumBook list; // TelNumBook 클래스 인스턴스 생성
	User user_struct; // User 스트럭트 인스턴스 생성
	int menuChoice; // 사용자가 입력한 메뉴의 번호를 저장하는 인스턴스.
	// int memberCount; // 회원수(데이터의 갯수를 알기 위해 등록된 회원의 수를 체크한다.)

	while (true) {
		// 메인 메뉴
		cout << "환영합니다. 이곳은 회원의 전화번호부를 관리하는 프로그램입니다." << endl;
		cout << "메뉴를 확인 후 입력칸에 입력해주세요!" << endl;
		cout << "  [1] 등록  [2] 조회  [3] 전체조회  [4] 프로그램 종료" << endl;
		cout << "입력 : ";
		cin >> menuChoice; // 사용자가 입력한 메뉴 번호를 저장한다.
		cout << endl;
		cout << "[ ------------------------------------------------------ ]" << endl;
		

		if (menuChoice == 1) {
			cout << "NAME : "; // 사용자가 이름을 입력함.
			cin >> user_struct.name; // struct로 생성한 User에 존재하는 name 변수로 데이터를 저장함.
			cout << "TEL : "; // 사용자가 전화번호를 입력함.
			cin >> user_struct.tel; // struct로 생성한 User에 존재하는 tel 변수로 데이터를 저장함.

			// 데이터가 잘 저장되는지 확인하기 위한 코드
			cout << user_struct.name << endl; // User에 저장된 데이터를 바로 출력함.
			cout << user_struct.tel << endl; // User에 저장된 데이터를 바로 출력함.

			list.addContact(user_struct); // TelNumBook 클래스에 addContact 함수로 user_struct(User 스트럭트에 저장된 정보)를 건네준다.
		}

		if (menuChoice == 3) {
			list.allUserList();
		}

		// [4] 프로그램 종료
		if (menuChoice == 4) break; // 반복문을 정지하여 프로그램을 종료시킴.
	}
	

	return 0;
}

/*
	2026/03/08
	- 프로젝트 시작
- 프로젝트의 설계를 하였음
- 먼저 데이터를 다루는 부분, 그 데이터를 갖고 기능들을 실행할 함수들의 모음(class), 그 모음들을 main() 함수에서 호출하여 프로그램을 동작하게 하려고 구상을 하였음.

좋았던 점
- 데이터의 규격(struct User)과 데이터를 다루는 시스템(class telNumBook)을 나눈 것은 객체 지향 프로그래밍의 핵심을 찌른 설계임.
- 확장성 : 나중에 주소나 이메일을 추가하고 싶을 때, 클래스를 건드릴 필요 없이 struct User 구조체만 수정하면 되기 때문에 유지보수가 아주 편한 구조임.

보완할 점
- 데이터의 개수 관리 : 클래스 내부의 배열 크기가 고정되어 있다면, 현재 몇 명의 사용자가 저장되었는지 알려주는 count 변수가 클래스 내부에 꼭 필요함.
- 입력 방식 : 함수 내에서 입력을 받아서 저장하게 된다면 현재 구조에서는 list[0].name; 이런식으로 배열의 0번쨰 칸에 저장하게 된다.
지금 방식으로 개발을 하면 당장의 문제는 없지만 나중에 파일에서 불러오기 기능을 만든다고 가정을 하였을때 "키보드로 입력 받는 함수"를 통째로 새로 짜야한다.
또한 정보를 클래스에 넘겨주기 전에 main()이나 별도 공간에서 "전화번호 형식이 맞나?"를 미리 검사할 수 있다.
유연한 위치 선정 : 지금 방식은 함수를 호출할 때마다 위치(list[0])에만 고정되어 저장되기 쉽지만, 데이터를 전달하는 방식은 클래스가 내부적으로 "지금 몇 명쨰지? 아, 5명이니까 6번 칸에 넣어야겠다." 라고 똑똑하게 판단할 수 있게 된다.

제미나이(AI)를 사용하여 추천받은 방법
- main()에서 User(struct로 만든 데이터 바구니) ㅇㅇㅇ; 를 만든다.
- cin >> 을 이용해 ㅇㅇㅇ.name과 ㅇㅇㅇ.tel에 값을 채운다.
- 클래스의 저장 함수를 호출하며(ㅇㅇㅇ)을 던져준다.(예시 : telNumBook.add(ㅇㅇㅇ); )
- list[count] = ㅇㅇㅇ; 라고 복사한 뒤, count를 1 올린다.

내일 이어서 해야할 부분
- private: 부분에 int count = 0; 이라는 변수를 만든다.
// 이 count로 list[0].name, list[1].name처럼 숫자를 직접 적을 필요가 없어짐. 항상 list[count] 라고 적으면 데이터가 들어올 때마다 count가 올라가면서 자동으로 다음 빈칸을 찾아가게 된다.

*/