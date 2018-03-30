//#include<iostream>
//#include<fstream>
//#include<string.h>
//
//std::string str;
//void swap( char &a,char &b )
//{
//	char temp;
//	temp = a;
//	a = b;
//	b = temp;
//}
//
//void perm( char list[], int k, int m )
//{
//	if( k == m )
//	{
//		for (int i=0;i<=m;i++)
//		{
//			std::cout << list[i];
//			str += list[i];
//		}
//		str += "\n";
//		std::cout << std::endl;
//	}
//	else
//	{
//		for ( int i = k; i <= m; i++ )
//		{
//			swap( list[k],list[i] );
//			perm( list, k + 1, m );
//			swap( list[k], list[i] );
//		}
//	}
//	
//}
//
//void writeFile( std::string name, std::string value )
//{
//	std::ofstream outfile( name, std::ios::out | std::ios::app );
//	if( !outfile.is_open( ) )
//		return;
//
//	int count = 0;
//	while( value.size( ) >= count )
//	{
//		outfile << value[count];
//		count ++;
//	}
//	outfile.close( );
//}
//
//void readFile( std::string name, char tmp[] )
//{
//	std::ifstream myfile( name, std::ios::app );
//	if ( !myfile.is_open( ) )
//		return;
//
//	myfile >> tmp;
//	myfile.close( );
//}
//
//int main( )
//{
//	char tmp[128] = { 0 };
//	readFile( "input.txt", tmp );
//	int count = 0;
//	while( tmp[count] != '\0' )
//		count ++;
//
//	perm( tmp, 0, count - 1 );
//	writeFile( "output.txt", str );
//	system( "pause" );
//	return 0;
//}