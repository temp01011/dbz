#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include &lt;string.h&gt;
void bubbleSort(int arr [ ],int n)
{
printf(&quot;\n Sorting Started \n&quot;);
for(int i=0;i&lt;n;i++)
{
for(int j=0;j&lt;n-1;j++)
{
if(arr[j] &gt; arr[j+1])
{
int temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp; } } }
printf(&quot;\n\n Sorting Completed! \n&quot;); }
void tostring(char str[], int num)
{
int i, rem, len = 0, n;
n = num;
while (n != 0)
{
len++;
n /= 10; }
for (i = 0; i &lt; len; i++)
{
rem = num % 10;
num = num / 10;
str[len - (i + 1)] = rem + &#39;0&#39;;
}
str[len] = &#39;\0&#39;;
}
void main(int argc, char *argv[])
{
printf(&quot;\n This is the main process: &quot;);
printf(&quot;\n Process Id: %d&quot;,getpid());
printf(&quot;\n Parent Id: %d&quot;,getppid());
int arr[] = {10,5,1,60,20};
int n = 5;
printf(&quot;\n\n Sorting Array using Bubble Sort:&quot;);
bubbleSort(arr,n);
printf(&quot;\n Forking the current process:&quot;);
pid_t cpid = fork();
//The pid_t data type is a signed integer type which is capable of representing a
process ID.
if(cpid &gt; 0)
{
printf(&quot;\n\n Parent is Running:\n ParentID: %d \n It&#39;s ID: %d
\n&quot;,getppid(),getpid());
printf(&quot;\n Parent is waiting for child to Complete! \n\n&quot;);
wait(NULL);
printf(&quot;\n\n Parent is Exiting!!\n&quot;);
}
else if(cpid == 0)
{
printf(&quot;\n\n Child is running:\n ParentID: %d \n It&#39;s ID: %d
\n&quot;,getppid(),getpid());
char *arrChar[n+1];
// Creating Ascii Character Array to Pass
// as command line Argument
arrChar[0] = (char *) &quot;child&quot;; // Arg 0 = name of executable file
for(int i=0;i&lt;n;i++)
{
char *string = malloc (sizeof(char) * (20));
tostring(string,arr[i]);
arrChar[i+1] = string;
}
arrChar[n+1] = NULL;
printf(&quot;\n\n Child Calling EXECV System Call:\n&quot;);
execv(&quot;./child&quot;,arrChar);
printf(&quot;\n\n Child EXECV Call Complete\n&quot;);
printf(&quot;\n\n Child Execution Complete \n&quot;);
}
else if(cpid &lt; 0)
{
printf(&quot;Error&quot;); } }