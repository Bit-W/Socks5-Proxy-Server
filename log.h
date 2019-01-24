In file included from epoll.h:3:0,
                 from tranfer.h:5,
                 from tranfer.cc:1:
common.h: In function ‘std::string GetFileName(const string&)’:
common.h:24:15: error: redefinition of ‘std::string GetFileName(const string&)’
 static string GetFileName(const string& path)
               ^
In file included from tranfer.h:4:0,
                 from tranfer.cc:1:
common.h:24:15: error: ‘std::string GetFileName(const string&)’ previously defined here
 static string GetFileName(const string& path)
               ^
In file included from epoll.h:3:0,
                 from tranfer.h:5,
                 from tranfer.cc:1:
common.h: In function ‘void __TraceLog(const char*, int, const char*, const char*, ...)’:
common.h:37:20: error: redefinition of ‘void __TraceLog(const char*, int, const char*, const char*, ...)’
 inline static void __TraceLog(const char* filename,int line, const char* function, const char*format, ...)
                    ^
In file included from tranfer.h:4:0,
                 from tranfer.cc:1:
common.h:37:20: error: ‘void __TraceLog(const char*, int, const char*, const char*, ...)’ previously defined here
 inline static void __TraceLog(const char* filename,int line, const char* function, const char*format, ...)
                    ^
In file included from epoll.h:3:0,
                 from tranfer.h:5,
                 from tranfer.cc:1:
common.h: In function ‘void __ErrorLog(const char*, int, const char*, const char*, ...)’:
common.h:51:20: error: redefinition of ‘void __ErrorLog(const char*, int, const char*, const char*, ...)’
 inline static void __ErrorLog(const char* filename,int line, const char* function, const char*
                    ^
In file included from tranfer.h:4:0,
                 from tranfer.cc:1:
common.h:51:20: error: ‘void __ErrorLog(const char*, int, const char*, const char*, ...)’ previously defined here
 inline static void __ErrorLog(const char* filename,int line, const char* function, const char*
                    ^
tranfer.cc: In member function ‘virtual void TranferServer::ReadEventHandler(int)’:
tranfer.cc:42:19: error: no match for ‘operator==’ (operand types are ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ and ‘int’)
             if(it == con->_serverchannel._fd)
                   ^
tranfer.cc:42:19: note: candidates are:
In file included from /usr/include/c++/4.8.2/map:60:0,
                 from common.h:15,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/stl_tree.h:217:7: note: bool std::_Rb_tree_iterator<_Tp>::operator==(const _Self&) const [with _Tp = std::pair<const int, EpollServer::Connect*>; std::_Rb_tree_iterator<_Tp>::_Self = std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >]
       operator==(const _Self& __x) const
       ^
/usr/include/c++/4.8.2/bits/stl_tree.h:217:7: note:   no known conversion for argument 1 from ‘int’ to ‘const _Self& {aka const std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >&}’
In file included from /usr/include/c++/4.8.2/iosfwd:40:0,
                 from /usr/include/c++/4.8.2/ios:38,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from common.h:4,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/postypes.h:216:5: note: template<class _StateT> bool std::operator==(const std::fpos<_StateT>&, const std::fpos<_StateT>&)
     operator==(const fpos<_StateT>& __lhs, const fpos<_StateT>& __rhs)
     ^
/usr/include/c++/4.8.2/bits/postypes.h:216:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ is not derived from ‘const std::fpos<_StateT>’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/bits/stl_algobase.h:64:0,
                 from /usr/include/c++/4.8.2/bits/char_traits.h:39,
                 from /usr/include/c++/4.8.2/ios:40,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from common.h:4,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/stl_pair.h:214:5: note: template<class _T1, class _T2> constexpr bool std::operator==(const std::pair<_T1, _T2>&, const std::pair<_T1, _T2>&)
     operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
     ^
/usr/include/c++/4.8.2/bits/stl_pair.h:214:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ is not derived from ‘const std::pair<_T1, _T2>’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/4.8.2/bits/char_traits.h:39,
                 from /usr/include/c++/4.8.2/ios:40,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from common.h:4,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/stl_iterator.h:291:5: note: template<class _Iterator> bool std::operator==(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_Iterator>&)
     operator==(const reverse_iterator<_Iterator>& __x,
     ^
/usr/include/c++/4.8.2/bits/stl_iterator.h:291:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ is not derived from ‘const std::reverse_iterator<_Iterator>’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/4.8.2/bits/char_traits.h:39,
                 from /usr/include/c++/4.8.2/ios:40,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from common.h:4,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/stl_iterator.h:341:5: note: template<class _IteratorL, class _IteratorR> bool std::operator==(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_IteratorR>&)
     operator==(const reverse_iterator<_IteratorL>& __x,
     ^
/usr/include/c++/4.8.2/bits/stl_iterator.h:341:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ is not derived from ‘const std::reverse_iterator<_Iterator>’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/4.8.2/bits/char_traits.h:39,
                 from /usr/include/c++/4.8.2/ios:40,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from common.h:4,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/stl_iterator.h:1031:5: note: template<class _IteratorL, class _IteratorR> bool std::operator==(const std::move_iterator<_Iterator>&, const std::move_iterator<_IteratorR>&)
     operator==(const move_iterator<_IteratorL>& __x,
     ^
/usr/include/c++/4.8.2/bits/stl_iterator.h:1031:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ is not derived from ‘const std::move_iterator<_Iterator>’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/bits/stl_algobase.h:67:0,
                 from /usr/include/c++/4.8.2/bits/char_traits.h:39,
                 from /usr/include/c++/4.8.2/ios:40,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from common.h:4,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/stl_iterator.h:1037:5: note: template<class _Iterator> bool std::operator==(const std::move_iterator<_Iterator>&, const std::move_iterator<_Iterator>&)
     operator==(const move_iterator<_Iterator>& __x,
     ^
/usr/include/c++/4.8.2/bits/stl_iterator.h:1037:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ is not derived from ‘const std::move_iterator<_Iterator>’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/string:41:0,
                 from /usr/include/c++/4.8.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.8.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.8.2/ios:42,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from common.h:4,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/allocator.h:128:5: note: template<class _T1, class _T2> bool std::operator==(const std::allocator<_CharT>&, const std::allocator<_T2>&)
     operator==(const allocator<_T1>&, const allocator<_T2>&)
     ^
/usr/include/c++/4.8.2/bits/allocator.h:128:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ is not derived from ‘const std::allocator<_CharT>’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/string:41:0,
                 from /usr/include/c++/4.8.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.8.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.8.2/ios:42,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from common.h:4,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/allocator.h:133:5: note: template<class _Tp> bool std::operator==(const std::allocator<_CharT>&, const std::allocator<_CharT>&)
     operator==(const allocator<_Tp>&, const allocator<_Tp>&)
     ^
/usr/include/c++/4.8.2/bits/allocator.h:133:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ is not derived from ‘const std::allocator<_CharT>’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/string:52:0,
                 from /usr/include/c++/4.8.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.8.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.8.2/ios:42,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from common.h:4,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/basic_string.h:2486:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const std::basic_string<_CharT, _Traits, _Alloc>&, const std::basic_string<_CharT, _Traits, _Alloc>&)
     operator==(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
     ^
/usr/include/c++/4.8.2/bits/basic_string.h:2486:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ is not derived from ‘const std::basic_string<_CharT, _Traits, _Alloc>’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/string:52:0,
                 from /usr/include/c++/4.8.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.8.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.8.2/ios:42,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from common.h:4,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/basic_string.h:2493:5: note: template<class _CharT> typename __gnu_cxx::__enable_if<std::__is_char<_Tp>::__value, bool>::__type std::operator==(const std::basic_string<_CharT>&, const std::basic_string<_CharT>&)
     operator==(const basic_string<_CharT>& __lhs,
     ^
/usr/include/c++/4.8.2/bits/basic_string.h:2493:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ is not derived from ‘const std::basic_string<_CharT>’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/string:52:0,
                 from /usr/include/c++/4.8.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.8.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.8.2/ios:42,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from common.h:4,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/basic_string.h:2507:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const _CharT*, const std::basic_string<_CharT, _Traits, _Alloc>&)
     operator==(const _CharT* __lhs,
     ^
/usr/include/c++/4.8.2/bits/basic_string.h:2507:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   mismatched types ‘const _CharT*’ and ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/string:52:0,
                 from /usr/include/c++/4.8.2/bits/locale_classes.h:40,
                 from /usr/include/c++/4.8.2/bits/ios_base.h:41,
                 from /usr/include/c++/4.8.2/ios:42,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from common.h:4,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/basic_string.h:2519:5: note: template<class _CharT, class _Traits, class _Alloc> bool std::operator==(const std::basic_string<_CharT, _Traits, _Alloc>&, const _CharT*)
     operator==(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
     ^
/usr/include/c++/4.8.2/bits/basic_string.h:2519:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ is not derived from ‘const std::basic_string<_CharT, _Traits, _Alloc>’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/bits/locale_facets.h:48:0,
                 from /usr/include/c++/4.8.2/bits/basic_ios.h:37,
                 from /usr/include/c++/4.8.2/ios:44,
                 from /usr/include/c++/4.8.2/ostream:38,
                 from /usr/include/c++/4.8.2/iostream:39,
                 from common.h:4,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/streambuf_iterator.h:204:5: note: template<class _CharT, class _Traits> bool std::operator==(const std::istreambuf_iterator<_CharT, _Traits>&, const std::istreambuf_iterator<_CharT, _Traits>&)
     operator==(const istreambuf_iterator<_CharT, _Traits>& __a,
     ^
/usr/include/c++/4.8.2/bits/streambuf_iterator.h:204:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ is not derived from ‘const std::istreambuf_iterator<_CharT, _Traits>’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/map:60:0,
                 from common.h:15,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/stl_tree.h:310:5: note: template<class _Val> bool std::operator==(const std::_Rb_tree_iterator<_Tp>&, const std::_Rb_tree_const_iterator<_Val>&)
     operator==(const _Rb_tree_iterator<_Val>& __x,
     ^
/usr/include/c++/4.8.2/bits/stl_tree.h:310:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   mismatched types ‘const std::_Rb_tree_const_iterator<_Val>’ and ‘int’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/map:60:0,
                 from common.h:15,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/stl_tree.h:907:5: note: template<class _Key, class _Val, class _KeyOfValue, class _Compare, class _Alloc> bool std::operator==(const std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>&, const std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>&)
     operator==(const _Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& __x,
     ^
/usr/include/c++/4.8.2/bits/stl_tree.h:907:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ is not derived from ‘const std::_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/tuple:39:0,
                 from /usr/include/c++/4.8.2/bits/stl_map.h:63,
                 from /usr/include/c++/4.8.2/map:61,
                 from common.h:15,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/array:228:5: note: template<class _Tp, long unsigned int _Nm> bool std::operator==(const std::array<_Tp, _Nm>&, const std::array<_Tp, _Nm>&)
     operator==(const array<_Tp, _Nm>& __one, const array<_Tp, _Nm>& __two)
     ^
/usr/include/c++/4.8.2/array:228:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ is not derived from ‘const std::array<_Tp, _Nm>’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/bits/stl_map.h:63:0,
                 from /usr/include/c++/4.8.2/map:61,
                 from common.h:15,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/tuple:813:5: note: template<class ... _TElements, class ... _UElements> constexpr bool std::operator==(const std::tuple<_Args1 ...>&, const std::tuple<_Args2 ...>&)
     operator==(const tuple<_TElements...>& __t,
     ^
/usr/include/c++/4.8.2/tuple:813:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ is not derived from ‘const std::tuple<_Args1 ...>’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/map:61:0,
                 from common.h:15,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/stl_map.h:962:5: note: template<class _Key, class _Tp, class _Compare, class _Alloc> bool std::operator==(const std::map<_Key, _Tp, _Compare, _Alloc>&, const std::map<_Key, _Tp, _Compare, _Alloc>&)
     operator==(const map<_Key, _Tp, _Compare, _Alloc>& __x,
     ^
/usr/include/c++/4.8.2/bits/stl_map.h:962:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ is not derived from ‘const std::map<_Key, _Tp, _Compare, _Alloc>’
             if(it == con->_serverchannel._fd)
                                          ^
In file included from /usr/include/c++/4.8.2/map:62:0,
                 from common.h:15,
                 from tranfer.h:4,
                 from tranfer.cc:1:
/usr/include/c++/4.8.2/bits/stl_multimap.h:864:5: note: template<class _Key, class _Tp, class _Compare, class _Alloc> bool std::operator==(const std::multimap<_Key, _Tp, _Compare, _Alloc>&, const std::multimap<_Key, _Tp, _Compare, _Alloc>&)
     operator==(const multimap<_Key, _Tp, _Compare, _Alloc>& __x,
     ^
/usr/include/c++/4.8.2/bits/stl_multimap.h:864:5: note:   template argument deduction/substitution failed:
tranfer.cc:42:42: note:   ‘std::_Rb_tree_iterator<std::pair<const int, EpollServer::Connect*> >’ is not derived from ‘const std::multimap<_Key, _Tp, _Compare, _Alloc>’
             if(it == con->_serverchannel._fd)
                                          ^
tranfer.cc: In function ‘int main()’:
tranfer.cc:56:16: error: cannot declare variable ‘server’ to be of abstract type ‘TranferServer’
  TranferServer server(8000,"127.0.0.1",8888);
                ^
In file included from tranfer.cc:1:0:
tranfer.h:6:7: note:   because the following virtual functions are pure within ‘TranferServer’:
 class TranferServer : public EpollServer
       ^
In file included from tranfer.h:5:0,
                 from tranfer.cc:1:
epoll.h:91:29: note: 	virtual void EpollServer::SendInLoop(int, const char*, int)
                virtual void SendInLoop(int fd,const char* arr,int len) = 0;
                             ^
epoll.h:93:29: note: 	virtual void EpollServer::Forwarding(EpollServer::Channel*, EpollServer::Channel*)
                virtual void Forwarding(Channel* clientchannel,Channel* serverchannel) = 0;
                             ^
epoll.h:97:16: note: 	virtual void EpollServer::WriteEventHandler(int)
   virtual void WriteEventHandler(int newaccept) = 0;
                ^
