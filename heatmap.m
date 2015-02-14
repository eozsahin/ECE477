
prob_of_odd = [16   0  29   0  32   0  24   0;  
              0  32   0  40   0  37   0  24;  
              29   0  42   0  45   0  37   0;  
              0  40   0  48   0  45   0  32;  
              32   0  45   0  48   0  40   0;  
              0  37   0  45   0  42   0  29;  
              24   0  37   0  40   0  32   0;  
              0  24   0  32   0  29   0  16;] 
          
          
prob_round_1 = [ 16   0  29   0  32   0  24   0 ;
  0  32   0  40   0  37   0  24 ;
 29   0  42   0  45   0  37   0 ;
  0  40   0  48   0  45   0  32 ;
 32   0  45   0  48   0  40   0 ;
  0  37   0  45   0  42   0  29 ;
 24   0  37   0  40   0  32   0 ;
  0  24   0  32   0  29   0  16 ;
]
prob_round_2 = [ 16   0  29   0  27   0  24   0 ;
  0  32   0  40   0  37   0  24 ;
 28   0  33   0   0   0  29   0 ;
  0  40   0  48   0  45   0  32 ;
 32   0  45   0  39   0  40   0 ;
  0  37   0  45   0  42   0  29 ;
 24   0  37   0  39   0  32   0 ;
  0  24   0  32   0  29   0  16 ;
]
prob_round_3 = [ 16   0  28   0  27   0  24   0 ;
  0  32   0  40   0  37   0  24 ;
 28   0  24   0   0   0  29   0 ;
  0  40   0  48   0  45   0  32 ;
 27   0   0   0  30   0  39   0 ;
  0  37   0  45   0  42   0  29 ;
 24   0  29   0  39   0  32   0 ;
  0  24   0  32   0  29   0  16 ;
]
prob_round_4 = [ 16   0  28   0  27   0  24   0 ;
  0  32   0  39   0  37   0  24 ;
 28   0  24   0   0   0  29   0 ;
  0  40   0  39   0  45   0  32 ;
 27   0   0   0  30   0  39   0 ;
  0  29   0   0   0  33   0  28 ;
 24   0  29   0  39   0  32   0 ;
  0  24   0  27   0  29   0  16 ;
]
prob_round_5 = [ 16   0  28   0  27   0  24   0 ;
  0  24   0   0   0  28   0  23 ;
 28   0  24   0   0   0  29   0 ;
  0  40   0  32   0  45   0  32 ;
 27   0   0   0  30   0  39   0 ;
  0  29   0   0   0  33   0  28 ;
 24   0  29   0  39   0  32   0 ;
  0  24   0  27   0  29   0  16 ;
]
prob_round_6 = [ 16   0  28   0  27   0  23   0 ;
  0  24   0   0   0  28   0  23 ;
 28   0  24   0   0   0  20   0 ;
  0  40   0  32   0  45   0  32 ;
 27   0   0   0  23   0   0   0 ;
  0  29   0   0   0  33   0  28 ;
 24   0  29   0  39   0  24   0 ;
  0  24   0  27   0  29   0  16 ;
]
    
colormap('hot')
imagesc(prob)
colorbar

figure(1)
colormap('hot')
colormap(flipud(colormap))
imagesc(prob_of_odd)
colorbar
figure(2)
colormap('hot')
colormap(flipud(colormap))
imagesc(prob_round_1)
colorbar
figure(3)
colormap('hot')
colormap(flipud(colormap))
imagesc(prob_round_2)
colorbar
figure(4)
colormap('hot')
colormap(flipud(colormap))
imagesc(prob_round_3)
colorbar
figure(5)
colormap('hot')
colormap(flipud(colormap))
imagesc(prob_round_4)
colorbar
figure(6)
colormap('hot')
colormap(flipud(colormap))
imagesc(prob_round_5)
colorbar
figure(7)
colormap('hot')
colormap(flipud(colormap))
imagesc(prob_round_6)
colorbar


oefterler
