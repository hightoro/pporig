/*|=====================================
 *|  Copyright (c) 2011-2014 hightoro
 *|  All rights reserved
 *|=====================================
 */

#ifndef HIGHTORO_CPP_ORIGINAL_COORD_CLASS_H
#define HIGHTORO_CPP_ORIGINAL_COORD_CLASS_H

#include <sstream>
#include <type_traits>
#include <utility>

/*+--------------------------------+*
 *|                                |*
 *|  File : coord.hpp              |*
 *|                                |*
 *|  Data : 04/01/2012             |*
 *|  TYPE : Class Header           |*
 *|  Base : (Nothing)              |*
 *|                                |*
 *+--------------------------------+*/

namespace pporig{

template <typename T,int N>
class basic_coord
{

};

//
template <typename T>
class basic_coord<T,2>
{
private:
  T x_;
  T y_;

public:
  T const& x;  // read-only menber
  T const& y;  // read-only menber

  /* ------------------------ *
   *|  Construct & Destruct  |*
   * ------------------------ */
  constexpr basic_coord():                  // Construct (Default)
    x_(0),y_(0),x(x_),y(y_){}
  ~basic_coord()=default;                   // Destruct

  explicit constexpr basic_coord(T nx,T ny):
    x_(nx),y_(ny),x(x_),y(y_){}

  /* ------------------ *
   *|  Copy Construct  |*
   * ------------------ */
  /*constexpr*/ basic_coord( const basic_coord& )=default;            // Copy Construct 1
  /*constexpr*/ basic_coord& operator=(const basic_coord&)=default;

  /* ------------------ *
   *|  Move Construct  |*
   * ------------------ */
  /*constexpr*/ basic_coord( basic_coord&& )=default;              // Move Construct 1
  /*constexpr*/ basic_coord& operator=( basic_coord&& )=default;   // Move Construct 2

  /* ---------------------- *
   *|  operator(compound)  |*
   * ---------------------- */
  /*constexpr*/ basic_coord& operator+= ( const basic_coord& obj )
  {
    x_+= obj.x_;
    y_+= obj.y_;
    return *this;
  }
  /*constexpr*/ basic_coord& operator-= ( const basic_coord& obj )
  {
    x_-= obj.x_;
    y_-= obj.y_;
    return *this;
  }
  //basic_coord<T>& operator *= ( const basic_coord<T>& );
  /*constexpr*/ basic_coord& operator*= ( const T& val )
  {
    x_*= val;
    y_*= val;
    return *this;
  }
  //basic_coord<T>& operator /= ( const basic_coord<T>& );
  /*constexpr*/ basic_coord& operator/= ( const T& val)
  {
    x_/= val;
    y_/= val;
    return *this;
  }
  /*constexpr*/ basic_coord& operator%= ( const T& val)
  {
    x_&= val;
    y_&= val;
    return *this;
  }

  /* -------------------- *
   *|  operator(binary)  |*
   * -------------------- */
  // append
  friend constexpr basic_coord operator+ (const basic_coord& lhs, const basic_coord& rhs)
  { return std::move(lhs += rhs); }
  friend constexpr basic_coord operator+ (basic_coord&& lhs, const basic_coord& rhs)
  { return std::move(lhs += rhs); }
  friend constexpr basic_coord operator+ (const basic_coord& lhs, basic_coord&& rhs)
  { return std::move(lhs += rhs); }
  friend constexpr basic_coord operator+ (basic_coord&& lhs, basic_coord&& rhs)
  { return std::move(lhs += rhs); }
  //
  friend constexpr basic_coord operator- (const basic_coord& lhs, const basic_coord& rhs)
  { return std::move(lhs -= rhs); }
  friend constexpr basic_coord operator- (basic_coord&& lhs, const basic_coord& rhs)
  { return std::move(lhs -= rhs); }
  friend constexpr basic_coord operator- (const basic_coord& lhs, basic_coord&& rhs)
  { return std::move(lhs -= rhs); }
  friend constexpr basic_coord operator- (basic_coord&& lhs, basic_coord&& rhs)
  { return std::move(lhs -= rhs); }
  //
  friend constexpr basic_coord operator* (const basic_coord& lhs, T rhs)
  { return std::move(lhs *= rhs); }
  friend constexpr basic_coord operator* (basic_coord&& lhs, const T& rhs)
  { return std::move(lhs *= rhs); }
  friend constexpr basic_coord operator* (T rhs, const basic_coord& lhs)
  { return std::move(lhs *= rhs); }
  friend constexpr basic_coord operator* (T rhs, basic_coord&& lhs)
  { return std::move(lhs *= rhs); }
  //
  friend constexpr basic_coord operator/ (const basic_coord& lhs, T rhs)
  { return std::move(lhs /= rhs); }
  friend constexpr basic_coord operator/ (basic_coord&& lhs, T rhs)
  { return std::move(lhs /= rhs); }
  friend constexpr basic_coord operator% (const basic_coord& lhs, T rhs)
  { return std::move(lhs %= rhs); }
  friend constexpr basic_coord operator% (basic_coord&& lhs, T rhs)
  { return std::move(lhs %= rhs); }

  /* ------------------- *
   *|  operator(unary)  |*
   * ------------------- */
  friend /*constexpr*/ basic_coord operator+ (const basic_coord& rhs)
  { return rhs; }
  friend /*constexpr*/ basic_coord operator- (const basic_coord& rhs)
  { return basic_coord(-rhs.x_,-rhs.y_); }

  /* --------------------- *
   *|  operator(compare)  |*
   * --------------------- */
  friend /*constexpr*/ T comp(const basic_coord& lhs, const basic_coord& rhs)
  {
    return
      (lhs.y_!=rhs.y_) ? (lhs.y_-rhs.y_) :
      (lhs.x_-rhs.x_) ;
  }
  friend /*constexpr*/ bool operator< (const basic_coord& lhs, const basic_coord& rhs)
  { return ( comp(lhs,rhs) <  0 ); }
  friend /*constexpr*/ bool operator> (const basic_coord& lhs, const basic_coord& rhs)
  { return ( comp(lhs,rhs) >  0 ); }
  friend /*constexpr*/ bool operator<=(const basic_coord& lhs, const basic_coord& rhs)
  { return ( comp(lhs,rhs) <= 0 ); }
  friend /*constexpr*/ bool operator>=(const basic_coord& lhs, const basic_coord& rhs)
  { return ( comp(lhs,rhs) >= 0 ); }
  friend /*constexpr*/ bool operator==(const basic_coord& lhs, const basic_coord& rhs)
  { return ( comp(lhs,rhs) == 0 ); }
  friend /*constexpr*/ bool operator!=(const basic_coord& lhs, const basic_coord& rhs)
  { return ( comp(lhs,rhs) != 0 ); }

  /* -------------------- *
   *|  operator(stream)  |*
   * -------------------- */
  //istream& operator >> <>( istream&, Basic_Coord<T>& );
  template<typename charT, typename traits>
  friend std::basic_ostream<charT,traits>& operator<< (std::basic_ostream<charT,traits>& ostr, const basic_coord& rhs)
  {
    std::basic_ostringstream<charT,traits> str;
    str << "(";
    str <<        rhs.x;
    str << "," << rhs.y;
    str << ")";
    return ostr << str.str();
  }

};

//
template <typename T>
class basic_coord<T,3>
{
private:
  T x_;
  T y_;
  T z_;

public:
  T const& x;  // read-only menber
  T const& y;  // read-only menber
  T const& z;  // read-only menber

};


/* -------------------- *
 *|  operator(global)  |*
 * -------------------- */
template<int N>
using coord =basic_coord<int,N>;
template<int N>
using fcoord=basic_coord<float,N>;
template<int N>
using dcoord=basic_coord<double,N>;
template<int N>
using scoord=basic_coord<short,N>;
template<int N>
using lcoord=basic_coord<long,N>;

}

#endif //CLASS_T_COORD_H
