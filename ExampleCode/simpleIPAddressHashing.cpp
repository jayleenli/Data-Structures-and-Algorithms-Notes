int Table::hashKey(string address) const
{
	//Take the IP address as a string, and retreive the numbers out. 
	//Then hash based based om the formula, ex X1.X2.X3.X4 ip address
	//key = a4X1+a3X2+a2X3+a1X4 mod 257
	//Create an array of 4, since IP address will always be 32 bits and have 4 numbers
	int arr[4] = { 0 };
	int j = 0; 
	int last = 0;
	for (unsigned int i = 0; i < address.length(); i++)
	{
		//if address[i] is '.', then split
		if (address[i] == '.') 
		{
			int num = stoi(address.substr(last, i-last));
			arr[j] = num;
			last = i + 1;
			j++;
		}
	}
	int last_num = stoi(address.substr(last, address.length()));
	arr[3] = last_num;

	//Get the key
	int key = a4*arr[0] + a3*arr[1] + a2*arr[2] + a1*arr[3];
	key = key % 257;
	return key;
}