#!/bin/sh 
print_list() 
{   
reset   echo "(1) - Search Address Book"   
echo "(2) - Add an Address Book entry"   
echo "(3) - Remove an Address Book entry"   echo "(4) - QUIT" 
 echo "SELECT THE NUMBER OF YOUR CHOICE ON THE LIST OR QUIT BY PRESSING q" 
} 
read_record()  
{ 
  RECORD=$1 
  ID=$(nl address.txt | grep -w $RECORD | awk '{print $2}') 
  NAME=$(nl address.txt | grep -w $RECORD | awk '{print $3}')   
  PHONE=$(nl address.txt | grep -w $RECORD | awk '{print $4}')   
  echo "Id: $ID , Name: $NAME , Phone: $PHONE" 
} 
insert_record() 
{  
 echo "Please Enter ID: "   read ID   
 echo "Please Enter Name: "   read NAME   
 echo "Please Enter Phone Number"   read PHONE   
 echo "ADDING ADDRESS BOOK ENTRY"   echo "$ID $NAME $PHONE" >> address.txt   
 echo "DATA INSERTED SUCCESSFULLY!" 
} 
remove_record() 
{   
DATA=$1   
echo "Removing address book entry"   sed -i "/$DATA/d" address.txt 
} 
go_back() 
{   echo "FOR MAIN MENU : m & FOR QUIT : q"   
	read CHOICE_MENU   
	if [ $CHOICE_MENU = "m" ]; 
	then 
    print_list 
    read CHOICE     
	elif [ $CHOICE_MENU = "q" ]; 
	then 
    exit 0     
	else 
    echo "The command you typed is not correct, FOR MAIN MENU : m & FOR QUIT : q" 
  fi 
} 
echo "WELCOME TO BOOK" 
print_list 
read CHOICE 
while [ $CHOICE -ne 4 ] 
do   
if [ $CHOICE -eq 1 ]; 
then     
echo "Please Enter ID or NAME or PHONE NUMBER"     
read QUERY     
read_record $QUERY     
go_back     
elif [ $CHOICE -eq 2 ]; 
then       
insert_record       
go_back     
elif [ $CHOICE -eq 3 ]; 
then       
echo "Please Enter ID or NAME or PHONE NUMBER of user that you want to remove"       
read USER       
remove_record $USER       
go_back 
    else       
	exit 0   
	fi 
	done 
