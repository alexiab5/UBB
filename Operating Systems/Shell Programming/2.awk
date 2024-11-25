NR>1 && $1 ~ /[A-Za-z0-9]{,4}/ {
	 if (!($1 in suma)) {
		 suma[$1] = 0;
	 }
	 suma[$1] += $2;
 }
 END {
	 for (i in suma) {
		 print i" "suma[i];
	 }
 }
