#include "LoginController.h"

LoginController::LoginController(){
    MemberList = new DbLinkedList();
}
void LoginController::SearchUser(string id, string pass){
    string member;
    string staff;
    if(MemberList->LoginMember(id, pass) == false /*&& D->LoginStaff(id, pass) == false*/){
        cout << "\tinvalid Username or Password" << endl
			<< "\t!!!!!Invalid Username or Password!!!!" << endl;
    }else if(MemberList->LoginMember(id, pass) == true){
        cout << "\tLogin Successfully" << endl;
        member = id.substr(0, id.find("")+2);
    }/*else if(D->LoginStaff(id, pass) == true){
        cout << "\tLogin Successfully" << endl;
        staff = id.substr(0, id.find("")+2);
    }*/
}
void LoginController::readfileMember(){
    Member m;
    string filein,Surname,Lastname,IdMember,password,Status;
	ifstream infile;
	infile.open("Member.dat", ios::in);
	if(infile.fail()){
		cout << "Not have file." << endl;
	}else{
		while(getline(infile, filein)){
            Surname = filein.substr(0, filein.find(","));
			    filein.erase(0, filein.find(",")+1);
            Lastname = filein.substr(0, filein.find(","));
			    filein.erase(0, filein.find(",")+1);
            IdMember = filein.substr(0, filein.find(","));
			    filein.erase(0, filein.find(",")+1);
            password = filein.substr(0, filein.find(","));
			    filein.erase(0, filein.find(",")+1);
            Status = filein.substr(0, filein.length());
			    filein.erase(0, filein.length());
            m.SetMember(Surname,Lastname,IdMember,password,Status);
            MemberList->AddMember(m);
    	}
	}
	infile.close();
}
LoginController::~LoginController(){
    MemberList = NULL;
}