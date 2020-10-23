emails="./emails.txt"
while IFS= read -r line
		do
			user=$(echo $line | cut -d "@" -f1)
			userdel -r $user
		done < "$emails"