/*
    就是处理数字有点烦..
*/

class Solution {
public:
string solveEquation(string equation) {

	int xsum = 0, numsum = 0;
	vector<pair<string, int>> sum;
	pair<string, int> v;
	bool status = true;
	bool zero = false;
	for (auto c : equation)
	{
		if (c == '+' || c == '-' || c == '=')
		{
			if (c == '+')
				status = true;
			else if(c == '-')
				status = false;
			else if (c == '=')
			{
				sum.push_back(v);
				v = std::make_pair("=", 0);
				status = true;
			}
			sum.push_back(v);
			v = std::make_pair("", 0);
			zero = false;
		}
		else if (isdigit(c))
		{
			v.second *= 10;
			if (status == true)
				v.second += c - 48;
			else
				v.second -= c - 48;
			if (v.second == 0)
				zero = true;
		}
		else if (c == 'x')
		{
			v.first = "x";
			if (zero == true)
				continue;
			if (v.second == 0)
			{
				if (status == true)
					v.second = 1;
				else
					v.second = -1;
			}
		}
	}
	sum.push_back(v);
	status = true;
	for (auto a : sum)
	{
		if (a.first == "")
		{
			if (status == true)
				numsum += a.second;
			else
				numsum -= a.second;
		}
		else if (a.first == "x")
		{
			if (status == true)
				xsum += a.second;
			else
				xsum -= a.second;
		}
		else
		{
			status = false;
		}
	}

	string s;
	if (xsum == 0 && numsum == 0)
		s = "Infinite solutions";
	else if (xsum == 0 && numsum != 0)
		s = "No solution";
	else
		s = "x=" + std::to_string(-numsum / xsum);
	return s;

}
};