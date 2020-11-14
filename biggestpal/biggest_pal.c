 #include <unistd.h>
 #include <stdlib.h>

 void biggest_pal(char *str)
 {
     int i;
     int l;
     int len;
     int mlen;
     int f;
     int start;
    
     len = 0;
     i = 1;
     mlen = 1;
     start = 0;
     while(str[len])
     {
         len++;
     }
     while(++i < len)
     {
         f = i - 1;
         l = i;
         while(f >= 0 && l < len && str[f] == str[l])
         {
             if(l - f + 1 > mlen)
             {
                 start = f;
                 mlen = l - f + 1;
             }
             f--;
             l++;
         }
         f = i - 1;
         l = i + 1;
         while (f >= 0 && l < len && str[f] == str[l])
         {
             if(l - f + 1 > mlen)
             {
                 start = f;
                 mlen = l - f + 1; 
             }
             f--;
             l++;
         }
     }
     f = start;
     while (f <= start + mlen - 1)
     {
         write(1,&str[f++],1);
     }
     
 }
 int main(int ac, char **av)
 {
     if(ac == 2)
     {
         biggest_pal(av[1]);
     }
     write(1,"\n",1);
     return (0);

 }
/* tests
 $> biggest_pal "abcba"
abcba
$> biggest_pal "aaaaaaaaaabbcbbaaaa"
aaaabbcbbaaaa
$> biggest_pal "aooibdaoiwhoihwdoinzeldaisaboyobasiadlezfdsfnslk"
zeldaisaboyobasiadlez
$> biggest_pal "aeibaabaammaabaalek"
aabaammaabaa
$> biggest_pal abeb qpinqwjobo qkmnwoiq

$> biggest_pal

$>*/
