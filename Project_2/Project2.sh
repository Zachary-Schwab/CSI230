#!/bin/bash

#file Project_2
# Intiates users from their emails as an input
# author zachary_schwab
# Project 2
# date 10/22/2020

#functions

#checks to make sure the user running the script is root
function checkroot()
{
if [[ "$UID" -eq "$ROOT_ID" ]]
then
	return $true
else
	return	$false
fi
}

#creates a password
function genpassword()
{
	password=$(openssl rand -base64 10)
	echo $password
}

#checks to make sure the user running the script is root
function createuser()
{
	username=$1
	group=$2
	password=$3

	#echo $username
	#echo $password
	if grep -q $username /etc/passwd
		then
			echo "$username:$password" | chpasswd
	else
		if [ -d "/home/$username" ] 
		then
		echo "home already exsisted for $username"
			useradd --badnames -s /bin/bash -d /home/$username $username; echo "$username:$password"| chpasswd
		else
			useradd --badnames -m -s /bin/bash $username; echo "$username:$password"| chpasswd
		fi
	fi
	chage --lastday 0 $user

}

#runs the rest of the functions and sends the emails out
function main()
{
groupname="CSI230"
emails="./emails.txt"
sendemail="zsschwab1@gmail.com"

	if checkroot;
	then
		if ! grep -q $groupname /etc/group
		then
			groupadd $groupname
		fi
		echo "What is the password for the sending email:"
		read -s emailpassword
		while IFS= read -r line
		do
			user=$(echo $line | cut -d "@" -f1)
			#echo $user
			password=$(genpassword)
			createuser $user $groupname $password
			
			curl --url 'smtps://smtp.gmail.com:465' --ssl-reqd --mail-from $sendemail --mail-rcpt $line --user $sendemail':'$emailpassword -T <(echo -e "From: $sendemail\nTo: $line \nSubject: Welcome to CSI230\n\n Your Account info is: \n Your username is: $user \n Your first time login password is $password")
			#echo "Welcome to CSI230 \n Your Account info is \n Your username is: $user \n Your first time login password is $password" | mail -s "This is the subject" $line
			
		done < "$emails"
	else
		echo "Script must be run by root"
	fi
}

#calls main
main
