// -*- c++ -*-
//  Generated by gtkmmproc from ./../base.gen_h -- DO NOT MODIFY!
#ifndef _GTKMM_BASE_H
#define _GTKMM_BASE_H

/* $Id: base.h,v 1.19 2000/11/15 02:23:11 kenelson Exp $ */

/* base.h
 *
 * Copyright (C) 1998-1999 The Gtk-- Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <gtk--config.h>
#include <string>
#include <iterator>
//#include <list>
//#include <vector>

#include <gdk--.h>
#include <gtk--/proxy.h>
#include <gtk--/marshal.h>

#ifdef GTKMM_CXX_AMBIGUOUS_TEMPLATES
#include <list>
#include <vector>
#endif

/* This aint pretty, but I don't know a better way to make
   sure things work when the stl classes are defined in a namespace */

// Gtk-- Base and other utility classes
#define GTK_VERSION_GT(major,minor) ((GTK_MAJOR_VERSION>major)||(GTK_MAJOR_VERSION==major)&&(GTK_MINOR_VERSION>minor))
#define GTK_VERSION_GE(major,minor) ((GTK_MAJOR_VERSION>major)||(GTK_MAJOR_VERSION==major)&&(GTK_MINOR_VERSION>=minor))
#define GTK_VERSION_EQ(major,minor) ((GTK_MAJOR_VERSION==major)&&(GTK_MINOR_VERSION==minor))
#define GTK_VERSION_NE(major,minor) ((GTK_MAJOR_VERSION!=major)||(GTK_MINOR_VERSION!=minor))
#define GTK_VERSION_LE(major,minor) ((GTK_MAJOR_VERSION<major)||(GTK_MAJOR_VERSION==major)&&(GTK_MINOR_VERSION<=minor))
#define GTK_VERSION_LT(major,minor) ((GTK_MAJOR_VERSION<major)||(GTK_MAJOR_VERSION==major)&&(GTK_MINOR_VERSION<minor))

#define GTK_VERSION_GT_MICRO(major,minor,micro) \
  ((GTK_MAJOR_VERSION>major)|| \
  (GTK_MAJOR_VERSION==major)&&(GTK_MINOR_VERSION>minor)||\
  (GTK_MAJOR_VERSION==major)&&(GTK_MINOR_VERSION==minor)&&(GTK_MICRO_VERSION>minor))

//using statements for standard library names.
//  If we are in a public header file, these names need to wrapped in
//    namespace Gtk, so that they do not pollute the global namespace
//    in user code.
//
//  If we are in a private implementation file, we want these names
//    imported into the global namespace for the sake of convenience.
//
//  Unfortunately, some of theses names (all the iterator tags) are
//    used in parts of this header file that are not inside namespace
//    Gtk. So when this file is included in a private implementation
//    file, we actually want these names to appear in *both* namespace
//    Gtk and the global namespace.

#ifdef GTKMM_IMPLEMENTATION
GTKMM_USING_STD_BIDIRECTIONAL_ITERATOR_TAG;  
GTKMM_USING_STD_FORWARD_ITERATOR_TAG;
GTKMM_USING_STD_INPUT_ITERATOR_TAG; 
GTKMM_USING_STD_STRING; 
#endif /* GTKMM_IMPLEMENTATION */

namespace Gtk
{
GTKMM_USING_STD_BIDIRECTIONAL_ITERATOR_TAG;  
GTKMM_USING_STD_FORWARD_ITERATOR_TAG;
GTKMM_USING_STD_INPUT_ITERATOR_TAG; 
GTKMM_USING_STD_STRING; 
}



/********************************************************************/

struct _GtkObject;

namespace Gtk
{


//Hook for faster data access
extern GQuark quark_;

/* Translating API */

/*
// used to give error on unwrapped types; connect Gtk-- crew
template <class C> struct NotWrapped;
// hook for C => C++ translation
template <class C> struct Wrap {typedef typename NotWrapped<C>::Type CppType;};
*/

class Object;
class ObjectClass;
typedef Object* (*Wrap_Func)(_GtkObject*);

// Generates an automatic wrapper for a gtkclass.
Object* wrap_auto(_GtkObject*);

// Register a new type for auto allocation.
void wrap_register(const string&,Wrap_Func);

// Request a specific wrapper for an object.
template <class Cpp>
Cpp* wrap_new(typename Cpp::BaseObjectType* o)
  {
   return (typename Cpp::CppClassType::wrap_new(o));
  }

// interface to gtk--
/* 
template <class C>
typename Wrap<C>::CppType* wrap(C* o)
  {
    return dynamic_cast<typename Wrap<C>::CppType*>(wrap_auto((GtkObject*)(o)));
  }
*/

/********************************************************************/

/* this class is a required stub implementation which does nothing! */
struct GtkBase { };
struct GtkBaseClass { };

class Base;
struct Base_Class
  { 
    typedef Base CppObjectType;
    static void class_init_function( GtkBaseClass *b)
      {(void)b;}
  };

//: This is an empty class needed by our code generator
#ifdef GTKMM_CXX_GAUB
struct Base_
  { void *this_;  
    Base_() : this_(this) {}
  };
class Base : private Base_, public virtual SigC::Object
#else 
class Base : public virtual SigC::Object
#endif
  {
    public:
      typedef Base          CppObjectType;
      typedef Base_Class    CppClassType;

      ~Base();

    protected:
      friend class Object_Class;
      static int get_type() {return 0;}
  };

/********************************************************************/

//: Input filter to screen out NULL inputs
// This class should not be used outside Gtk-- parameter lists.
// It is intended to be used whereever a string is passed
// as an input that may be 0.  (Gtk-- internal)
class nstring : public string {
  bool null_;
public:
  explicit nstring();
  nstring(string str);
  // lets not use "NULL" in gtk--. 0 is much more portable in c++.
  nstring(const char *s);
  ~nstring();

  // this function should be used in place of c_str
  // if NULL is a valid value.
  const char * gc_str() const;

  // returns 1 if this was created from a NULL pointer
  int null()  const
    {return null_;}
};

/********************************************************************/
} /* namespace Gtk */

template <class T> struct G_List_Iterator;
template <class T> struct G_List_ConstIterator;
template <class T> struct G_List_ReverseIterator;

// Most of these methods in the non-template classes needs to be moved
// to implementation.

//: (internal) GList wrapper for gtk-- owned lists.
class G_ListImpl
{
  GList *list_;
  G_ListImpl(const G_ListImpl&);
public:
  G_ListImpl(): list_(0) {}
  ~G_ListImpl()         {g_list_free(list_);}

  GList* const &  list() const {return list_;}
  GList*& list() {return list_;} // is it allowed, if we own the list??

  int index_of(gpointer data)
    {return g_list_index(list_,data);}
  int position(GList *pos)
    {return g_list_position(list_,pos);}
  GList* first() const
    {return g_list_first(list_);}
  GList* last() const
    {return g_list_last(list_);}

  size_t size() const
    { return g_list_length(list_); }
  bool empty() const
    { return size()==0; }

  void reverse()
    {list_=g_list_reverse(list_);}

  GList* insert(GList* pos,gpointer data);

  void remove(gpointer data)
    {list_=g_list_remove(list_,data);}

  GList* erase(GList* pos);

  void clear()
    {
      g_list_free(list_);
      list_=0;
    }
};

//: (internal) GList wrapper for gtk+ owned lists.
class G_ListWrap
{
  GList*& list_;
public:
  G_ListWrap(GList*& l)           : list_(l)       {}
  G_ListWrap(const G_ListWrap& l) : list_(l.list_) {}

  GList*& list() {return list_;}
  GList* const& list() const {return list_;}

  int index_of(gpointer data)
    {return g_list_index(list_,data);}
  int position(GList *pos)
    {return g_list_position(list_,pos);}
  GList* first()
    {return g_list_first(list_);}
  GList* last()
    {return g_list_last(list_);}

  size_t size() const
    { return g_list_length(list_); }
  bool empty() const
    { return size()==0; }

  void reverse()
    {list_=g_list_reverse(list_);}

  GList* insert(GList* pos,gpointer data);

  void remove(gpointer data)
    {list_=g_list_remove(list_,data);}

  GList* erase(GList* pos);

  void clear()
    {
      g_list_free(list_);
      list_=0;
    }
};

//: STL C++ style wrapper for GList
//- This wraps simple types for use in Glist.  It is not intended
//- to replace STL lists, only be used where a GList is needed to wrap
//- gtk+ internals.  It can only hold C types.  They must not have a dtor,
//- nor should be larger than the size of a pointer.
template <class T,class Impl=G_ListImpl>
class G_List
{
public:
  typedef G_List<T,Impl>                         Self;
  typedef G_List_Iterator<T>                     iterator;
  typedef G_List_ConstIterator<iterator>         const_iterator;
  typedef G_List_ReverseIterator<iterator>       reverse_iterator;
  typedef G_List_ReverseIterator<const_iterator> reverse_const_iterator;
  typedef size_t                                 size_type;

private:
  Impl impl;
  G_List(const Self& x);

  gpointer to_pointer(const T& d)
    { return const_cast<gpointer&>(reinterpret_cast<const void* const&>(d)); }

public:
  G_List()              : impl()  {}
  G_List(const Impl& i) : impl(i) {}
  ~G_List()                       {}

  GList* & glist() const { return impl.list(); }

  iterator begin()             { return iterator(impl.list(),impl.first()); }
  iterator end()               { return iterator(impl.list(),(GList*)0); }
  const_iterator begin() const { return const_iterator(impl.list(),impl.first()); }
  const_iterator end()   const { return const_iterator(impl.list(),(GList*)0); }
  reverse_iterator rbegin()    { return reverse_const_iterator(end()); }
  reverse_iterator rend()      { return reverse_const_iterator(begin()); }
  reverse_const_iterator rbegin() const { return reverse_const_iterator(end());}
  reverse_const_iterator rend()   const { return reverse_const_iterator(begin());}

  iterator insert(iterator pos,const T& data)
    { return iterator(impl.list(),impl.insert(pos.node,to_pointer(data))); }

  iterator erase(iterator pos)
    { return iterator(impl.erase(pos));}
  void remove(const T& data)
    { impl.remove(to_pointer(data)); }
  void clear() {impl.clear();}

  void push_front(const T& data) { insert(begin(), data); }
  void push_back(const T& data)  { insert(end(), data); }
  void pop_front()               { erase(begin()); }
  void pop_back()                { erase(impl.last());}

  void reverse()                 { impl.reverse();}

  size_type size() const         { return impl.size(); }
  bool empty() const             { return impl.empty(); }

};


/********************************************************************/


extern gpointer gtkmm_null_pointer;

template <class T>
struct G_List_Iterator
{
  typedef Gtk::bidirectional_iterator_tag iterator_category;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  typedef T  value_type;
  typedef T* pointer;
  typedef T& reference;

  GList * const *head;
  GList * node;

  typedef G_List_Iterator<T> Self;

  G_List_Iterator(GList* const& h,GList *n) : head(&h)    ,node(n)      {}
  G_List_Iterator()                   : head(0)     ,node(0)      {}
  G_List_Iterator(const Self& x)      : head(x.head),node(x.node) {}

  bool operator==(const Self& x) const { return node == x.node; }
  bool operator!=(const Self& x) const { return node != x.node; }

  Self&  operator++()
  {
    if (!node)
      node=g_list_first(*head);
    else
      node=(GList*)g_list_next(node);
    return *this;
  }

  Self operator++(int)
  {
    Self tmp = *this;
    ++*this;
    return tmp;
  }

  Self&  operator--()
  {
    if (!node)
      node=g_list_last(*head);
    else
      node=(GList*)g_list_previous(node);
    return *this;
  }

  Self operator--(int)
  {
    Self tmp = *this;
    --*this;
    return tmp;
  }

  reference operator*()  const 
  { 
    return (T&)((node)?(*node).data:gtkmm_null_pointer); 
  }
  
  pointer operator -> () const { return &operator*(); }
};

template <class T>
struct G_SList_Iterator
{
  typedef Gtk::forward_iterator_tag iterator_category;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  typedef T  value_type;
  typedef T* pointer;
  typedef T& reference;

  GSList *node;
  typedef G_SList_Iterator<T> Self;

  G_SList_Iterator(GSList *n)     : node(n)      {}
  G_SList_Iterator()              : node(0)      {}
  G_SList_Iterator(const Self& x) : node(x.node) {}

  bool operator==(const Self& x) const { return node == x.node; }
  bool operator!=(const Self& x) const { return node != x.node; }

  Self&  operator++()
  {
    node = g_slist_next(node);
    return *this;
  }

  Self operator++(int)
  {
    Self tmp = *this;
    ++*this;
    return tmp;
  }

  reference operator*()  const { return reinterpret_cast<T&>((node)?(*node).data:gtkmm_null_pointer); }
  pointer operator -> () const { return &operator*(); }
};

// this iterator variation returns interf (wrapped from impl)
//  Equivelency  G_List_Cpp_Iterator<GtkWidget,Gtk_Widget>
//     => list<Gtk_Widget*>::iterator
template<class impl, class interf>
struct G_List_Cpp_Iterator {
  typedef Gtk::input_iterator_tag iterator_category;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  typedef interf*  value_type;
  typedef interf** pointer;
  typedef interf*& reference;

  typedef G_List_Cpp_Iterator<impl,interf> Self;

  GList **head;
  GList *node;

  bool operator==(const Self& x) const { return node == x.node; }
  bool operator!=(const Self& x) const { return node != x.node; }

  G_List_Cpp_Iterator(GList*& h,GList *n) : head(&h)    ,node(n)      {}
  G_List_Cpp_Iterator()                   : head(0)     ,node(0)      {}
  G_List_Cpp_Iterator(const Self& x)      : head(x.head),node(x.node) {}

  value_type operator*() const
  {
    if (node && node->data)
      return Gtk::wrap(static_cast<impl*>((*node).data));
    return 0;
  }

  Self&  operator++()
  {
    if (!node)
      node=g_list_first(*head);
    else
      node = (GList *)g_list_next(node);
    return *this;
  }

  Self operator++(int)
  {
    Self tmp = *this;
    ++*this;
    return tmp;
  }

  Self&  operator--()
  {
    if (!node)
      node=g_list_last(*head);
    else
      node = (GList *)g_list_previous(node);
    return *this;
  }

  Self operator--(int)
  {
    Self tmp = *this;
    --*this;
    return tmp;
  }

};

template <class B>
struct G_List_ReverseIterator: private B
{
  typedef typename B::iterator_category iterator_category;
  typedef typename B::size_type         size_type;
  typedef typename B::difference_type   difference_type;

  typedef typename B::value_type        value_type;
  typedef typename B::pointer           pointer;
  typedef typename B::reference         reference;

  typedef G_List_ReverseIterator<B>    Self;

  bool operator==(const Self& x) const { return B::operator==(x); }
  bool operator!=(const Self& x) const { return B::operator!=(x); }

  G_List_ReverseIterator(GList* const& h,GList *n) : B(h,n) {}
  G_List_ReverseIterator()                   : B()    {}
  G_List_ReverseIterator(const Self& x)      : B(x)   {}
  G_List_ReverseIterator(const B& x)         : B(x)   { ++(*this); }

  Self& operator++()   {B::operator--(); return *this;}
  Self& operator--()   {B::operator++(); return *this;}
  Self operator++(int) {Self s=*this; B::operator--(); return s;}
  Self operator--(int) {Self s=*this; B::operator++(); return s;}

  reference operator*()  const { return B::operator*(); }
  pointer operator -> () const { return B::operator->(); }
};

template <class B>
struct G_List_ConstIterator: public B
{
  typedef typename B::iterator_category iterator_category;
  typedef typename B::size_type         size_type;
  typedef typename B::difference_type   difference_type;

  typedef const typename B::value_type  value_type;
  typedef const typename B::pointer     pointer;
  typedef const typename B::reference   reference;

  typedef G_List_ConstIterator<B>    Self;

  bool operator==(const Self& x) const { return B::operator==(x); }
  bool operator!=(const Self& x) const { return B::operator!=(x); }

  G_List_ConstIterator(GList* const& h,GList *n) : B(h,n) {}
  G_List_ConstIterator()                   : B()    {}
  G_List_ConstIterator(const Self& x)      : B(x)   {}
  G_List_ConstIterator(const B& x)         : B(x)   {}

  Self& operator++()   {B::operator++(); return *this;}
  Self& operator--()   {B::operator--(); return *this;}
  Self operator++(int) {Self s=*this; B::operator++(); return s;}
  Self operator--(int) {Self s=*this; B::operator--(); return s;}

  value_type operator*()  const { return B::operator*(); }
  pointer operator -> () const { return B::operator->(); }
};

// for compatablity
typedef G_List<int> G_IntList;
typedef G_List_Iterator<int> G_IntList_Iterator;

/********************************************************************/


namespace Gtk
{

// Converter functions to simplify the list building
template <class T>
inline const char* gtkmm_to_cstring (const T& t)
  { return t; }

template <>
inline const char* gtkmm_to_cstring<string>(const string& t)
  { return t.c_str(); }

template <>
inline const char* gtkmm_to_cstring<nstring>(const nstring& t)
  { return t.gc_str(); }

#ifndef GTKMM_MSC  
namespace SArray_Helpers
{

typedef const char* cstring;

// Function for counting the items in a zero-terminated collection
template <class Iterator>
size_t count_strings(Iterator iter)
{
  size_t s = 0;
  for (; *iter != 0; ++iter, ++s);
  return s;
}

// create_array creates an array of const char* and fills it with the
// contents of a collection. The array returned by create_array is owned
// by the caller, but the strings that the array holds are not.
template <class Iterator>
const char* const* create_array(Iterator iter, size_t size)
{
  cstring* data = new cstring[size + 1];
  data[size] = 0;
  
  for (size_t i = 0; i < size; ++iter, ++i)
    data[i] = gtkmm_to_cstring(*iter);

  return data;
}

#ifndef GTKMM_CXX_AMBIGUOUS_TEMPLATES
// This is a traits class that specifies how to copy a collection in
// the most efficient manner possible. The default specialization is
// designed for containers that define begin(), end() and size().
template <class T>
struct Traits
{
  static bool get_owned() { return true; }
  static const char* const* get_data(const T& t)
    { return create_array(t.begin(), t.size()); }
 static size_t get_size(const T& t) { return t.size(); }
};

// This is a specialization for zero-terminated arrays of (const) char*
template <class T>
struct Traits<T*>
{
  static bool get_owned() { return false; }
  static const char* const* get_data(const T* t)
    { return const_cast<const char* const*>(t); }
  static size_t get_size(const T* t) { return count_strings(t); }
};
 
// This specialization is for built in arrays of (const) char*, note that
// the arrays must still be zero-terminated, even though the size is known
// at compile time.
template <class T, size_t N>
struct Traits<T[N]> : Traits<T*>
{
  static size_t get_size(const T*) { return N - 1; }
};
#endif

// (internal) This is equivalent to a const char**
// This is a converter so you would not declare any of this type.
// It can be constructed implicitly from any container that has the
// standard member functions begin() and size() which holds elements of
// any string type. It can also be constructed implicitly from arrays of
// (const) char*.
// Construction from a sequence defined by a pair of iterators is also
// supported. This is most useful for arrays of string types other than
// char* or const char* and for copying only part of a container.
class SArray
{
  SArray& operator=(const SArray& c); // Not implemented

  const bool owned_;
  const size_t size_;
  const cstring* const data_;

public:
  // Standard typedefs
  typedef const char* value_type;
  typedef const char* const* iterator;
  typedef const char* const* const_iterator;
  typedef const char* const* pointer;
  typedef const char* const* const_pointer;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  // Copy constructor
  SArray(const SArray& c)
    : owned_(false), size_(c.size_), data_(c.data_) { }

#ifndef GTKMM_CXX_AMBIGUOUS_TEMPLATES
  // copy other containers
  template <class T>
  SArray(const T& t)
    : owned_(Traits<T>::get_owned()), size_(Traits<T>::get_size(t)),
     data_(Traits<T>::get_data(t))
    { }
#else
  // compiler can't handle template cctor properly.
  SArray(const list<string>& c)     
    : owned_(true), size_(c.size()),
      data_(create_array(c.begin(), c.size())) { }
  SArray(const vector<string>& c)  
    : owned_(true), size_(c.size()),
      data_(create_array(c.begin(), c.size())) { }
  SArray(const list<nstring>& c) 
    : owned_(true), size_(c.size()),
      data_(create_array(c.begin(), c.size())) { }
  SArray(const vector<nstring>& c)
    : owned_(true), size_(c.size()),
      data_(create_array(c.begin(), c.size())) { }
  SArray(const list<const char*>& c)
    : owned_(true), size_(c.size()),
      data_(create_array(c.begin(), c.size())) { }
  SArray(const vector<const char*>& c)
    : owned_(true), size_(c.size()),
      data_(create_array(c.begin(), c.size())) { }
  SArray(const char* const* p) 
    : owned_(false), size_(count_strings(p)), data_(p) { }
#endif

  // copy a sequence
  template <class Iterator>
  SArray(Iterator b,Iterator e)
    : owned_(true), size_(std::distance(b, e)), data_(create_array(b, size_))
    { }

  ~SArray()
    { if (owned_) delete [] const_cast<const char**>(data_); }

  operator const char** () const
    { return const_cast<const char**>(data_); }

  size_t size() const { return size_; }

  const char* const* begin() const
    { return data_; }
  const char* const* end() const
    { return data_ + size_; }
  const char* operator[](size_t n) const
    { return data_[n]; }
};
  
inline bool operator==(const SArray& x, const SArray& y)
{
  return x.begin() == y.begin();
}
  
} // namespace SArray_Helpers

using SArray_Helpers::SArray;

#else

// (internal) This is equivelent to a const char**
// This is a converter so you would not declare any of this type.
class SArray
{
protected:
  typedef const char* cstring;

  bool owned_;
  cstring *data_;
  size_t size_;

  void a_alloc(size_t size);

  template <class Iterator>
  void a_dup(Iterator b,Iterator e);

  // block assignment
  template <class A>
  SArray & operator=(A) {
      return *this;
  }

public:
  operator const char** () const
  { return data_; }

  SArray(const SArray& c);

  SArray(const char** data);

  size_t size(void) const { return size_; }

#ifndef GTKMM_CXX_AMBIGUOUS_TEMPLATES
  // copy a other containers
  template <class Container>
  SArray(const Container& c)
  { a_dup(c.begin(),c.end()); }
#else
  // compiler can't handle template cctor properly.
  SArray(const list<string>& c)        { a_dup(c.begin(),c.end()); }
  SArray(const vector<string>& c)      { a_dup(c.begin(),c.end()); }
  SArray(const list<nstring>& c)  { a_dup(c.begin(),c.end()); }
  SArray(const vector<nstring>& c){ a_dup(c.begin(),c.end()); }
  SArray(const list<const char*>& c)   { a_dup(c.begin(),c.end()); }
  SArray(const vector<const char*>& c) { a_dup(c.begin(),c.end()); }
#endif

  // copy a partial container
  template <class Iterator>
  SArray(Iterator b,Iterator e)
  { a_dup(b,e); }

  ~SArray();
};


template <class Iterator>
void SArray::a_dup(Iterator b,Iterator e)
{
  Iterator iter;

  for (iter=b, size_ = 0; iter!=e; ++iter, ++size_);

  a_alloc(size_);

  unsigned int i;
  
  for (iter=b, i=0; iter!=e; ++iter, ++i)
    data_[i]=gtkmm_to_cstring(*iter);
}
#endif

/********************************************************************/


//: (internal) Convert C++ list to C list
//- Returns allocated GList of gtk+ objects from a C++ container
//- of gtk-- objects.  
template <class iterator>
GList* gtkmm_build_glist(iterator start,iterator stop)
  {
    GList *items=0;
    while (start!=stop)
      {
        if (*start)
          {
           if (!items)
             items=g_list_append(items,(*start)->gtkobj());
           else
             {
               g_list_append(items,(*start)->gtkobj());
               items=items->next;
             }
          }
        ++start;
      }
    if (items) return g_list_first(items);
    return 0;
  }

} /* namespace Gtk */


#endif
