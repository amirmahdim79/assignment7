#ifndef PROGRAM_H_
#define PROGRAM_H_

#include <string>
#include <vector>

#include "user.h"
#include "publisher.h"
#include "customer.h"
#include "exceptions.h"
#include "movie.h"
#include "notification.h"
#include "money.h"
#include "rate.h"
#include "comment.h"
#include "reply.h"
#include "admin.h"

using namespace std;

class Program {
private:
    int id = 1;
    int film_id = 1;
    int active_user = -1;
    vector<string> methods = {"GET", "PUT", "POST", "DELETE"};
    vector<string> commands = {"signup", "login", "delete_film", "put_films", "delete_comments", "logout", "films", "followers", "money", "published",
                                "replies", "comments", "followers", "buy", "rate", "purchased",
                                "notifications", "notificationsread", ""};
    vector<string> usernames;
    vector<User*> users;
    vector<Film*> all_films;
    vector<Money*> money_server;
    vector<Money*> server_earnings;
    int all_money = 0;
public:
    void run();

    Film* get_film(int film_id);

    int character_location(string line, char character);
    int find_user(int id);

    void increase_id();
    void increase_film_id();
    void break_command(string line);
    void read_method_command(string line, string command);
    void read_username_password(string line, string &username, string &password);
    void delete_film_from_database(int id);
    void add_money_to_server(Money* money);

    void check_method(string method);
    void check_command(string command);
    void check_username(string username);
    void check_user_exist(string username);
    void check_access_publisher();
    void check_film_exists(int id);

    void get_command();
    void do_command(string line, string method, string command);
    void add_film(string line, int user);
    void edit_film(string line, int user);
    void delete_film(string line, int user);
    void show_published(string line, int user);
    void follow(string line, int user);
    void add_money(string line, int user);
    void search_films(string line, int user);
    void buy_film(string line, int user);
    void rate_film(string line, int user);
    void comment_on_film(string line, int user);
    void show_purchased(string line, int user);
    void show_notifications(string line, int user);
    void show_read_notifications(string line, int user);
    void film_details(int film_id);
    void show_comments_and_replies(int film_id);
    void show_recommendation_films(int film_id);
    void add_reply(string line, int user);
    void delete_comment(string line, int user);



    void signup(string line);
    void login(string username, string password);

    vector<string> break_to_words(string line);
};

#endif