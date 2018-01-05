#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
/*
designing tinyurl type service to shorten large urls
- 6 char URL, given that URLs are stored in a database
and every URL has an associated integer id
- note: long url should be uniquely identifiable from a short
url, need a bijective function

simple solution: hashing
- use hash function to convert long string to short string
- hashing may have collisions (2 long urls map to same short url)
- need unique short url for every long url to access the long url back

better solution: use integer id stored in db and convert
the integer to a character string that is at most 6 chars long
AKA base conversion problem where 10 digit input number is
converted inot 6 char long string

note: there are 62 possible characters, 26 uppercase, 26
lower case, 10 digits
** task is to then convert decimal to base 62 number
- to get original long url, need to get url id in db
- id can be obtained using base 62 decimal conversion
*/

// function to generate short url from integer ID

string idToShortURL(long int n) {
	// use a map to store the 62 possible chars
	char map[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	string shortURL;

	// convert the given int into a base 62 number
	while(n) {
		// use the map to store the actual character: 
		shortURL.push_back(map[n%62]);
		n = n/62; 
	}

	//reverse shorturl to complete base conversion;
	reverse(shortURL.begin(), shortURL.end());

	return shortURL;

}

long int shortURLToId(string shortURL) {
	long int id = 0; // initlize with zero

	// base conversion logic: 
	for (int i = 0; i < shortURL.length(); i++) {
		if ('a' <= shortURL[i] && shortURL[i] <= 'z')
			id = id*62 + shortURL[i] - 'a'; // ascii converrsion
		if ('A' <= shortURL[i] && shortURL[i] <= 'Z')
			id = id*62 + shortURL[i] - 'A' + 26; // location in the map
		if ('0' <= shortURL[i] && shortURL[i] <= '9')
			id = id*62 + shortURL[i] - '0' + 52;
	}
	return id;
}


int main() {
	int n = 14423;
	string shortURL = idToShortURL(n);

	cout << "generated short url is: " << shortURL << endl;
	cout << "id from url is: " << shortURLToId(shortURL) << endl;;

	return 0;
}

