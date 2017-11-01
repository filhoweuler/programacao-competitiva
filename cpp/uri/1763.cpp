#include <bits/stdc++.h>

using namespace std;

int main () {              
	map<string, string> tt;
	tt["brasil"] = "Feliz Natal!";
	tt["alemanha"] = "Frohliche Weihnachten!";
	tt["austria"] = "Frohe Weihnacht!";
	tt["coreia"] = "Chuk Sung Tan!";
	tt["espanha"] = "Feliz Navidad!";
	tt["grecia"] = "Kala Christougena!";
	tt["estados-unidos"] = "Merry Christmas!";
	tt["inglaterra"] = "Merry Christmas!";
	tt["australia"] = "Merry Christmas!";
	tt["portugal"] = "Feliz Natal!";
	tt["suecia"] = "God Jul!";
	tt["turquia"] = "Mutlu Noeller";
	tt["argentina"] = "Feliz Navidad!";
	tt["chile"] = "Feliz Navidad!";
	tt["mexico"] = "Feliz Navidad!";
	tt["antardida"] = "Merry Christmas!";
	tt["canada"] = "Merry Christmas!";
	tt["irlanda"] = "Nollaig Shona Dhuit!";
	tt["belgica"] = "Zalig Kerstfeest!";
	tt["italia"] = "Buon Natale!";
	tt["libia"] = "Buon Natale!";
	tt["siria"] = "Milad Mubarak!";
	tt["marrocos"] = "Milad Mubarak!";
	tt["japao"] = "Merii Kurisumasu!";
	
	string s;
	while (getline(cin, s)) {
		if (tt.find(s) != tt.end())
			cout << tt[s] << endl;
		else
			cout << "--- NOT FOUND ---" << endl;
	}
	
	
}
