#ifndef USER_H_
#define USER_H_

#include <string>
#include <vector>
#include "movie.h"
#include "notification.h"

class User {
protected:
    int id;
    int age;
    string username;
    string email;
    string password;
    bool publisher;
    vector<Film*> films;
    vector<User*> followers;
    vector<User*> following;
    vector<Notification*> notifications;
public:
    int get_id();
    string get_password();
    string get_username();
    void follow(User* user);

    virtual int get_films_size() {return films.size();}
    virtual Film* get_film(int id) {}
    virtual vector<Film*> get_films() {}

    bool is_publisher();

    virtual void add_film(Film* film) {}
    virtual void has_film(int id) {}
    virtual void delete_film(int id) {}
    virtual void show_followers() {}
    virtual void show_all_films() {}
    virtual void add_to_notifications(Notification* notif);
    virtual void add_to_followers(User* user);
};

#endif