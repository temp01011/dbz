#include &lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
void main(int argc, char *argv[])
{
int *data = (int *) malloc((argc) * sizeof(int));
printf(&quot;\n Argc:%d&quot;,argc);
for(int i = 0;i &lt; argc;i++)
{
data[i] = atoi(argv[i]);
}
printf(&quot;\n Printing Element in Reverse:&quot;);
for(int i = argc-1; i&gt;0;i--)
{
printf(&quot; %d &quot;,data[i]);
}
printf(&quot;\n\n EXCEV task Completed \n&quot;); }

