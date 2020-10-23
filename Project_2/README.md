for each e-mail in the list of emails (ex: bilbo.baggins@shire.net)
	https://www.cyberciti.biz/faq/unix-howto-read-line-by-line-from-file/

extract a username by grabbing the text to the left of the @ delimiter
	https://www.geeksforgeeks.org/cut-command-linux-examples/	

create a random password (openssl is great for this) of at least 12 characters
	https://raymii.org/s/snippets/OpenSSL_Password_Generator.html

create a user account using the username, password
	https://serverfault.com/questions/868092/how-do-i-create-a-user-with-a-password-in-one-line-in-bash-on-redhat

ensure that it has a home directory
	https://www.cyberciti.biz/faq/howto-check-if-a-directory-exists-in-a-bash-shellscript/
		

that the default shell is bash.
	https://www.tecmint.com/add-users-in-linux/#:~:text=To%20add%2Fcreate%20a%20new,already%20exists%20on%20the%20system).	

Also make sure the user needs to change their password on first login (see the chage command).
	https://www.tecmint.com/force-user-to-change-password-next-login-in-linux/

Add each user to the CSI230 group (you will need to create this if it doesn't exist)
	https://stackoverflow.com/questions/29073210/how-to-check-if-a-group-exists-and-add-if-it-doesnt-in-linux-shell-script

if the user already exists, update their password
	https://linuxize.com/post/how-to-list-users-in-linux/
	https://www.systutorials.com/changing-linux-users-password-in-one-command-line/

send the user an e-mail with their initial username/password (google the following terms "send a gmail from bash 2fa")
	https://stackoverflow.com/questions/4316730/hiding-user-input-on-terminal-in-linux-script
	https://curl.haxx.se/docs/manpage.html
	https://stackoverflow.com/questions/8260858/how-to-send-email-from-terminal

end email loop
