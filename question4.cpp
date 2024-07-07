#include <iostream>
#include <string.h>
#include <functional>
#include <string>
using namespace std;
class user
{
protected:
    string username;
    string email;
    string password;
    string hash_password;

public:
    user(string username, string email, string password)
    {
        this->username = username;
        this->email = email;
        this->password = password;
    }
    void encrypt()
    {
        int length = password.length();
        hash<string> hasher;
        size_t hashvalue = hasher(password);
        cout <<"hash password:"<<hashvalue << endl;
    }
    string get_password()
    {
        return password;
    }
    virtual bool verifypw(string p)
    {
        if (this->password == p)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    virtual ~user()
    {
    }
};
class post
{
protected:
    string postId;
    string content;
    int likes;
    int comments;
    int views;

public:
    post(string postId, string content)
    {
        this->postId = postId;
        this->content = content;
        this->likes = 0;
        this->comments = 0;
        this->views = 0;
    }
    void addviews()
    {
        this->views++;
    }
    void addcomment()
    {
        comments++;
    }
    void addlike()
    {
        likes++;
    }
    void display()
    {
        cout << "Post Id: " << postId << endl;
        cout << "Content: " << content << endl;
        cout << "Likes: " << likes << endl;
        cout << "Comments: " << comments << endl;
        cout << "Views: " << views << endl;
    }
};
class regular_user : public user
{
    static const int max_post = 5;
    post *p[max_post];
    int count;

public:
    regular_user(string username, string email, string password) : user(username, email, password)
    {
        count = 0;
    }
    void addpost(post *p)
    {
        if (count <= max_post)
        {
            this->p[count] = p;
            count++;
        }
        else
        {
            cout << "You have reached the limit of 5 posts" << endl;
        }
    }
    void viewfeed()
    {
        for (int i = 0; i < count; i++)
        {
            p[i]->display();
        }
    }
    bool verifypw(string p) override
    {
        if (get_password() == p)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class bussiness_user : public user
{
    int max_post = 10;
    int count;

public:
    bussiness_user(string username, string email, string password) : user(username, email, password)
    {
        count = 0;
    }
    void promote(post *p)
    {
        if (count < max_post)
        {
            p->addlike();
            p->addcomment();
            p->addviews();
            p->addlike();
            p->addcomment();
            p->addlike();
            p->display();
            cout << "Post has been promoted successfully" << endl;
            count++;
        }
        else
        {
            cout << "You have reached the maximum limit of promoted posts." << endl;
        }
    }

    bool verifypw(string p) override
    {
        if (get_password() == p)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    cout << "mohid raheel khan 23k-3000" << endl;
    regular_user r("regular-user", "regular@example.com", "Pubgpro1");
 

    r.encrypt();
    

    post p1("1", "adventure land");
    post p2("2", "my idol");
    post p3("3", "night futsal");
    if (r.verifypw("Pubgpro1") == true)
    {
        r.addpost(&p1);
        r.addpost(&p2);
        r.addpost(&p3);
        r.viewfeed();
    }
    else
    {
        cout << "wrong password" << endl;
    }
       bussiness_user b("bussiness-user", "bussiness@example.com", "Pubgpro2");
       cout<<endl;
       b.encrypt();

    if (b.verifypw("Pubgpro2") == true)
    {
        cout << endl;
        b.promote(&p1);
    }
    else
    {
        cout << "wrong password" << endl;
    }

    return 0;
}
