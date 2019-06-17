//Source : https://stackoverflow.com/questions/5739937/using-getlinecin-s-after-cin
//Incorrect code
int t;
cin >> t;
string s;
getline (cin, s);

// The above code will not read the input string because it will read the '\n' left in cin's buffer //

//Correct code
int t;
cin >> t;
cin.ignore();
string s;
getline (cin , s);

			/ *** /

//Source : https://stackoverflow.com/questions/213907/c-stdendl-vs-n

//Difference between '\n' and endl
//Though both is used to start from the next line, but '\n' doesnot empty the buffer, i.e doesnot flushes
//the output buffer whereas endl does. 
//So use '\n' to print from next line whenever flushing is not required, as it reduces the time. Sometimes using endl to print ans to a large number 
//of queries might lead to TLE