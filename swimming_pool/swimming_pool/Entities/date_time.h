#pragma once
#ifndef date_time_h
#define date_time_h

#include <string>
#include <sstream>
#include <iomanip>
#include <locale>

class date_time
{
private:
    static std::string format_;
    tm& inner_tm_ = *new tm;
    
public:
    explicit date_time ();
    explicit date_time (tm& tm);
    explicit date_time (std::string const& str);
    
    std::string to_string () const;
    int get_total_seconds () const;
    
    static date_time& now ();
    static date_time& parse (std::string const& value);
    static date_time& parse (tm& value);
    
    date_time& operator = (date_time const& dt);
    
    bool operator == (date_time const& dt) const;
    bool operator != (date_time const& dt) const;
    bool operator >  (date_time const& dt) const;
    bool operator >= (date_time const& dt) const;
    bool operator <  (date_time const& dt) const;
    bool operator <= (date_time const& dt) const;
    
private:
    static tm* parse_str (std::string const& value);
};

std::ostream& operator << (std::ostream& lhs, date_time const& dt);

#endif /* date_time_h */
