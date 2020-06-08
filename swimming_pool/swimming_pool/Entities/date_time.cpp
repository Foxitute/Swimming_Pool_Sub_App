#include "date_time.h"

//  2020/04/10 TIME/10:33:25   ---   Y/M/D TIME/H:M:S
std::string date_time::format_{"%Y/%m/%d TIME/%H:%M:%S"};

date_time::date_time () = default;
date_time::date_time (tm& tm) : inner_tm_(tm) { }
date_time::date_time (std::string const& str) : date_time(*parse_str(str)) { }
    
std::string date_time::to_string () const
{
    std::stringstream ss;
    ss << std::put_time(&inner_tm_, format_.c_str());
    return ss.str();
}

int date_time::get_total_seconds () const
{
    return static_cast<int>(mktime(&inner_tm_));
}

// this Function runs only on Linux-Bases OS
date_time& date_time::now ()
{
    time_t today = time(nullptr);
    tm* tm_today = new tm;
    localtime_r(&today, tm_today);
    return parse(*tm_today);
}

// for Windows OS uncomment the following Function:

//date_time& date_time::now ()
//{
//    time_t today = time(nullptr);
//    tm* tm_today = new tm;
//    localtime_s(tm_today, &today);
//    return parse(*tm_today);
//}

date_time& date_time::parse (std::string const& value)
{
    return *new date_time(value);
}

date_time& date_time::parse (tm& value)
{
    return *new date_time(value);
}
    
date_time& date_time::operator = (date_time const& dt)
{
    std::swap(inner_tm_, dt.inner_tm_);
    return *this;
}

bool date_time::operator == (date_time const& dt) const
{
    return get_total_seconds() == dt.get_total_seconds();
}

bool date_time::operator != (date_time const& dt) const
{
    return get_total_seconds() != dt.get_total_seconds();
}

bool date_time::operator > (date_time const& dt) const
{
    return get_total_seconds() > dt.get_total_seconds();
}

bool date_time::operator >= (date_time const& dt) const
{
    return get_total_seconds() >= dt.get_total_seconds();
}

bool date_time::operator < (date_time const& dt) const
{
    return get_total_seconds() < dt.get_total_seconds();
}

bool date_time::operator <= (date_time const& dt) const
{
    return get_total_seconds() <= dt.get_total_seconds();
}

tm* date_time::parse_str (std::string const& value)
{
    std::stringstream ss (value);
    tm* time = new tm;
    ss >> std::get_time(time, format_.c_str());
    return time;
}

std::ostream& operator << (std::ostream& lhs, date_time const& dt)
{
    lhs << dt.to_string();
    return lhs;
}
