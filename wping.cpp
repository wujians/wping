#include <iostream>
#include <string>
#include <getopt.h>

using namespace std;

void ShowHelp(bool bVer)
{
    if (bVer)
    {
        cout << "Ping Utility V1.0" << endl;
    }
    cout << "usage: wping [options] dest_ip" << endl;
    cout << "options:" << endl;
    cout << "    -h    show help info" << endl;
    cout << "    -c    constantly ping" << endl;
    cout << "    -s    ping all hosts in the subnet, the dest_ip should be xxx.xxx.xxx" << endl;
}

bool g_bConstPing = false;
bool g_bSubnet = false;

int main(int argc, char* argv[])
{
    int opt = 0;

    if (argc == 1)
    {
        ShowHelp(true);
        return 0;
    }

    while ( (opt = getopt(argc, argv, "hcs")) != -1)
    {
        switch (opt)
        {
        case 'h':
            ShowHelp(false);
            return 0;

        case 'c':
            g_bConstPing = true;
            break;

        case 's':
            g_bSubnet = true;
            break;

        case '?':
            ShowHelp(false);
            return -1;
        }
    }

    string strTargetIP = argv[optind];
    







    return 0;
}