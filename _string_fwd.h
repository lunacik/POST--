/*
 * Copyright (c) 1997
 * Silicon Graphics Computer Systems, Inc.
 *
 * Copyright (c) 1999 
 * Boris Fomitchev
 *
 * This material is provided "as is", with absolutely no warranty expressed
 * or implied. Any use is at your own risk.
 *
 * Permission to use or copy this software for any purpose is hereby granted 
 * without fee, provided the above notices are retained on all copies.
 * Permission to modify the code and to distribute modified code is granted,
 * provided the above notices are retained, and a notice that the code was
 * modified is included with the above copyright notice.
 *
 */

#ifndef _STLP_STRING_FWD_H
#define _STLP_STRING_FWD_H

#ifndef _STLP_IOSFWD
# include <iosfwd>
#endif

_STLP_BEGIN_NAMESPACE

# if !defined (_STLP_LIMITED_DEFAULT_TEMPLATES)
template <class _CharT, 
          class _Traits = char_traits<_CharT>, 
          class _Alloc = allocator<_CharT> >
class basic_string;
# else
template <class _CharT, 
          class _Traits, 
          class _Alloc>
class basic_string;
# endif /* _STLP_LIMITED_DEFAULT_TEMPLATES */

typedef basic_string<char, char_traits<char>, post_alloc<char> > string;

#  ifdef _STLP_HAS_WCHAR_T
typedef basic_string<wchar_t, char_traits<wchar_t>, post_alloc<wchar_t> > wstring;
#  endif

# ifdef _STLP_OWN_IOSTREAMS
_STLP_DECLSPEC const char*  _STLP_CALL
__get_c_string(const string& __str);
# else
template <class _CharT, class _Traits, class _Alloc>
const char* _STLP_CALL
__get_c_string(const basic_string<_CharT, _Traits, _Alloc>& __str);
# endif

_STLP_END_NAMESPACE

#endif /* _STLP_STRING_FWD_H */

// Local Variables:
// mode:C++
// End: