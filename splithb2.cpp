// Contributed by Henrique Bucher (http://www.vitorian.com/)
// Requires SSE4.2
#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <unistd.h>
#include <smmintrin.h>

int main()
{
   long count = 0;
   timespec start;
   clock_gettime(CLOCK_MONOTONIC, &start);

   std::size_t numWords = 0;
   std::size_t numChars = 0;

   const __m128i LF  = _mm_set1_epi8( '\n' );
   const __m128i SPC = _mm_set1_epi8( ' ' );

   unsigned bufsize = 1024*1024;
   char* buf = (char*)aligned_alloc( 16, bufsize );

   while ( true ) {
       int nb = ::fread( buf, 1, bufsize, stdin );
       if ( nb<=0 ) break;

       int pos = 0;
       while ( pos<nb ) {
           union { __m128i res; uint16_t resu[8]; };
           __m128i u = _mm_loadu_si128 ((__m128i *) &buf[pos] );
           unsigned sz = nb-pos;
           if ( sz>16 ) sz = 16;
           res = _mm_cmpestrm( SPC, 1, u, sz,
                               (_SIDD_UBYTE_OPS | _SIDD_CMP_EQUAL_ANY | _SIDD_BIT_MASK) );
           uint16_t spcbits = resu[0];
           res = _mm_cmpestrm( LF, 1, u, sz,
                               (_SIDD_UBYTE_OPS | _SIDD_CMP_EQUAL_ANY | _SIDD_BIT_MASK) );
           uint16_t lfbits = resu[0];

           unsigned numspc = __builtin_popcount( spcbits );
           unsigned numlf  = __builtin_popcount( lfbits );

           numWords += numspc + numlf;
           count += numlf;
           numChars += sz - (numspc+numlf);

           pos += sz;
       }
   }

   timespec end;
   clock_gettime(CLOCK_MONOTONIC, &end);
   const double sec = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
   std::cerr << "C++   : Saw " << count << " lines (" << numWords << " words/" << numChars << " chars) in " << std::fixed << std::setprecision(1) << sec << " seconds." ;

   if (sec > 0)
   {
      const double lps = count / sec;
      std::cerr << "  Crunch speed: " << std::fixed << std::setprecision(1) << lps << std::endl;
   }
   else
      std::cerr << std::endl;

   return 0;
}
