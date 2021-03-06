/*
 * main.cpp
 *
 *  Created on: Sep 2, 2013
 *      Author: ryan
 */


#include <iostream>
#include <iomanip>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

using namespace std;

class Console{
	private:
		string cmd;
		string currDir;
	public:
		Console():cmd(""),currDir("/home/ryan")
			{}

		void usrinput(){
			//get command from user input
			do{
		    	cout<<currDir<<" >";
		    	getline(cin,cmd);
		    	if (cmd=="list-short"){
		    		lsShort(currDir); //call list-short
		    	}else if(cmd=="list-long"){
		    		lsLong(currDir); // call list-long
		    	}else if(cmd.find("change")!=string::npos){
		    		string targetDir=cmd.erase(0,7); //get dir by removing "change" from command
		    		currDir=targetDir;
		    	}
		    }while(cmd != "exit");

		}

		//list-short
		void lsShort(string currDir){
			DIR 			*dir;
			struct dirent 	*entry;
			char			entryName[256];

		    if(dir=opendir(currDir.c_str())){

		    	while((entry = readdir(dir))!=NULL){
					strcpy(entryName,entry->d_name);
					cout<<entryName<<"\n";
				}
				closedir(dir);
			}else{
				cout<<"error in openning the file \n";
			}
		}//list short

		//list-long
		void lsLong(string currDir){
			DIR 			*dir;
			struct dirent 	*entry;
			struct stat 	statBuf;
			struct passwd  	*pwd;
			struct group   	*grp;
			int 			mode;
			char			entryName[256];
			char 			modeStr[10];
			char			usrName[32];
			char			grpName[32];
			int				nLink;
			long			size;
			string			strTime;

		    if(dir=opendir(currDir.c_str())){
				while((entry = readdir(dir))!=NULL){

					strcpy(entryName,entry->d_name);

					//file information
					if(stat(entry->d_name, &statBuf) !=-1){

						//get permissions string
						mode=statBuf.st_mode;
						strcpy( modeStr, "----------" );
						if ( S_ISDIR(mode) )  modeStr[0] = 'd';    //directory
					    if ( S_ISCHR(mode) )  modeStr[0] = 'c';    //char devices
					    if ( S_ISBLK(mode) )  modeStr[0] = 'b';    //block device
					    if ( mode & S_IRUSR ) modeStr[1] = 'r';    //owner
					    if ( mode & S_IWUSR ) modeStr[2] = 'w';
					    if ( mode & S_IXUSR ) modeStr[3] = 'x';
					    if ( mode & S_IRGRP ) modeStr[4] = 'r';    //group
					    if ( mode & S_IWGRP ) modeStr[5] = 'w';
					    if ( mode & S_IXGRP ) modeStr[6] = 'x';
					    if ( mode & S_IROTH ) modeStr[7] = 'r';    //other
					    if ( mode & S_IWOTH ) modeStr[8] = 'w';
					    if ( mode & S_IXOTH ) modeStr[9] = 'x';

					    //get user name
					    if ((pwd = getpwuid(statBuf.st_uid)) != NULL){
					    	strcpy(usrName,pwd->pw_name);
					    }
					    //get group name
					    if ((grp = getgrgid(statBuf.st_gid)) != NULL){
					    	strcpy(grpName,grp->gr_name);
					    }
					    //get link
						nLink=statBuf.st_nlink;
						//get size
						size=statBuf.st_size;
						//get modification time
						char* mTime=ctime(&statBuf.st_mtime)+4;
						strTime=mTime;
						strTime=strTime.substr(0,strTime.length()-1);//remove the "/n" character
						//get entry name

					}
					//print
					cout<<modeStr<<" "<<nLink<<" "<<usrName<<" "<<grpName<<" "<<size<<" "<<strTime<<" "<<entryName<<"\n";
				}
				closedir(dir);
			}else{
				cout<<"error in openning the file \n";
			}
		}//list long
};

int main(){

	time_t timer; //create timer object

	time(&timer); //get system time
	cout<<"Command line program start. System time:"<<ctime(&timer)<<endl;

	Console console;
	console.usrinput();

	time(&timer); //get system time
	cout<<"Command line program end. System time:"<<ctime(&timer)<<endl;

    return 0;
}


