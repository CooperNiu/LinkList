??   / *   a l g o 2 - 1 0 . c  ??????????????????????????m????????????:????????????????| 2 . 1 3????   * / 
   # i n c l u d e " c 1 . h " 
   t y p e d e f   i n t   E l e m T y p e ; 
   # i n c l u d e " c 2 - 2 . h " 
   # i n c l u d e " b o 2 - 4 . c " 
 
   v o i d   M e r g e L i s t _ C L ( L i n k L i s t   * L a , L i n k L i s t   L b ) 
   { 
       L i n k L i s t   p = L b - > n e x t ; 
       L b - > n e x t = ( * L a ) - > n e x t ; 
       ( * L a ) - > n e x t = p - > n e x t ; 
       f r e e ( p ) ; 
       * L a = L b ; 
   } 
 
   v o i d   v i s i t ( E l e m T y p e   c ) 
   { 
       p r i n t f ( " % d   " , c ) ; 
   } 
 
   v o i d   m a i n ( ) 
   { 
       i n t   n = 5 , i ; 
       L i n k L i s t   L a , L b ; 
       I n i t L i s t _ C L ( & L a ) ; 
       f o r ( i = 1 ; i < = n ; i + + ) 
           L i s t I n s e r t _ C L ( & L a , i , i ) ; 
       p r i n t f ( " L a = " ) ;   / *  ?????????????? L a????????????   * / 
       L i s t T r a v e r s e _ C L ( L a , v i s i t ) ; 
       I n i t L i s t _ C L ( & L b ) ; 
       f o r ( i = 1 ; i < = n ; i + + ) 
           L i s t I n s e r t _ C L ( & L b , 1 , i * 2 ) ; 
       p r i n t f ( " L b = " ) ;   / *  ?????????????? L b????????????   * / 
       L i s t T r a v e r s e _ C L ( L b , v i s i t ) ; 
       M e r g e L i s t _ C L ( & L a , L b ) ; 
       p r i n t f ( " L a + L b = " ) ;   / *  ???????????????????????????????????   * / 
       L i s t T r a v e r s e _ C L ( L a , v i s i t ) ; 
   } 
