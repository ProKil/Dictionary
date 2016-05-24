#include <iostream>
#include <string>
#include <vector>
#include "word_library.h"
#include "search_history_library.h"
#include "review_history_library.h"
#include "search_strategy.h"
#include "file_translation.h"
#include "review_strategy.h"

using namespace std;
extern word_library word_lib;
extern review_history_library review_history_lib;

int main()
{
	//review_strategy today_review;
	cout << "Loaded.\n";
	/*while(1){
	    cout << today_review.get_next_word() << endl << "Do you know this word?" << endl;
	    string respond;
        int j;
        getline(cin, respond);
        if(respond == "yes") j = 2;
            else if(respond == "no") j = 0;
                else if(respond == "quit") goto l1;
                    else j = 1;
	    today_review.input_performance(j);
	    if(today_review.all_correct()) break;
	}
l1:    cout << "Congratulations" << endl;*/
	vector<string> today_list = review_history_lib.get_list(0);
	for(int i = 0; i < today_list.size(); i ++)
		cout << today_list[i] << endl;


	for(int i = 0; i < 5; i ++)
	{
		string rand_word = word_lib.get_random_new_word();
		//cout << i << endl;
		review_history_lib.insert_review_history(rand_word);
	}
	vector<string> today_list2 = review_history_lib.get_list(0);
	for(int i = 0; i < 5; i ++)
		cout << today_list2[i] << endl;
    return 0;
}
