# Lecture 8
## Routers路由器
* 路由器：route data from one place to another.
* One of the ways we've dealt with the IPv4 addressing problem is to start assigning multiple people to the same IP address. The IP address is assigned to a router, whose job it is to act as a traffic cop that allows data requests from all of the devices on your local network to be processed through a single IP address.
* Packets of data(数据包) are transferred from one router to another, from one computer to another.
* TCP/IP are two protocols that allow computers to transfer data between them over the internet.
* IP (Internet Protocol, 互联网协议，网络层协议) is a way by which computers can identify one another across the internet. Every computer has a unique address in the world. Addresses are in this form: #.#.#.# (#: 0~255)
  * IPv4: 32 bits to store address(4个8字节)
  * IPv6: 128 bits to store address(8个16字节[0, ffff])
    * 1234:5678:90ab:cdef:fedc:ba09:8765:4321
    * 若中间有很多0，也可省略：2001:4860:4860::8844 == 2001:4860:4860:0:0:0:0:8844
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_8_HTML_CSS_JavaScript/images/image-5.png?raw=true)
* TCP (transmission control protocol，传输层协议), is used to distinguish web services from one another.
  * 序列号
  * 端口号（source port、destination port）
    * 80——HTTP(web browsing)
    * 443——HTTPS(secure web browsing)
    * 21——FTP(file transfer)
    * 25——SMTP(e-mail)
    * 53——DNS
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_8_HTML_CSS_JavaScript/images/image-6.png?raw=true)
* IP is responsible for getting it from one machine to another. TCP is responsible for getting it to the correct program.（IP协议负责网络层的寻址和路由，是互联网的基础；而TCP协议在IP协议的基础上提供可靠、有序的传输服务）
* DHCP, dynamic host configuration protocol, dhcp server has a list of addresses that it can validly assign, and answer the question: what IP address should I use.
## DNS
* DNS, or domain name systems, is a collection of servers on the internet that are used to route website addresses like harvard.edu to a specific IP address.
* DNS simply hold a table or database that links specific, fully qualified domain names to specific IP addresses.
## HTTP
* HTTP or hypertext(超文本) transfer protocol is an application-level protocol that specifically dictates the format by which clients request web pages from a server, and the format via which servers return information to clients.
* When you see an address such as https://www.example.com, you are actually implicitly visiting that address with a / at the end of it.
* The path is what exists after that slash. For example, https://www.example.com/folder/file.html visits example.com and browses(浏览) to the folder, and then visits the file named file.html.
* domain name: example.com
* www is a host name of a specific server that lives in example.com
* The .com is called a top-level domain that is used to denote the location or type of organization associated with this address.
* https in this address is the protocol that is used to connect to that web address.
* HTTP utilizes GET or POST requests to ask for information from a server.
```
request
  GET / HTTP/2(版本2)
  Host: www.harvard.edu

response
  HTTP/2 200
  Content-Type: text/html

request
  GET /cats.html HTTP/2
  Host: cats.com

response
  HTTP/2 404
  Content-Type: text/html

可通过以下命令模拟浏览器向server发送请求
curl -I https://www.harvard.edu/

curl -I https://harvard.edu
curl -I http://www.harvard.edu/
response
  HTTP/2 301

response code
  200 OK
  301 Moved Permanently, page is now at a new location, automic redirects built in to most browsers
  302 Found, page is now at a new location temporarily
  304 Not Modified
  304 Temporary Redirect
  401 Unauthorized(未经授权), page typically requires login credentials
  403 Forbidden, server will not allow this request
  404 Not Found, server cannot find what was asked for
  418 I'm a Teapot(服务器拒绝请求)
  500 Internal Server Error, generic server failure in responding to the otherwise-valid request
  503 Service Unavailable
```
## HTML
* HTML or hypertext markup language is made up of tags, each of which may have some attributes(属性) that describe it.
```html
<!DOCTYPE html> <!-- 文档类型声明 -->

<!-- Demonstrates HTML -->

<!-- tag: html  -->
<!-- attribute: lang, value: en, 界面语言为英语  -->
<html lang="en">
    <head>
        <title>
            hello, title
        </title>
    </head>
    <body>
        hello, body
    </body>
</html>
```
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_8_HTML_CSS_JavaScript/images/image.png?raw=true)
* You can serve your code by typing `http-server`. This serve is now available on a very long URL. If you click it, you can visit the website with your own code.
* `http-server` creates a server that listens to the HTTP requests, so when I click on something on the HTML page send a request that a server can respond to.
* The browser will read your HTML file top to bottom and left to right.
* Whitespace and indentation is effectively ignored in HTML, you will need to use paragraph tags to open and close a paragraph.
```html
<b></b> <!-- 加粗 -->
<i></i> <!-- 斜体 -->
<u></u> <!-- 下划线 -->
<p></p> <!-- 段落 -->
<hX></hX> <!-- 标题 -->
<hr> <!-- 水平分割线 -->
X = 1, 2, 3, 4, 5, 6
<ul></ul> <!-- 无序列表 -->
<ol></ol> <!-- 有序列表 -->
<ol start=6></ol> <!-- 从6开始的有序列表 -->
<li></li> <!-- 列表中的元素 -->
<table></table> <!-- 表格 -->
<tr></tr> <!-- table row -->
<td></td> <!-- table data -->
<form></form> <!-- 表单，用于处理用户输入 -->
<input name=X type=Y /> <!-- 创建表单输入控件 -->
<div></div> <!-- 分块 -->
<a href=X></a> <!-- 超链接 -->
<img src=X ... /> <!-- 图片 -->
<!DOCTYPE html> <!-- html开始 -->
<strong></strong> <!-- 用于表示文本中的重要部分 -->
<audio></audio> <!-- 音频 -->
```
```html
<div>
    <form>
        Text: <input name="a" type="text" />
        Password: <input name="b" type="password" />
        Radio: <input name="c" type="radio" />
        Checkbox: <input name="d" type="checkbox" />
        Submit: <input name="e" type="submit" />
    </form>
</div>
```
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_8_HTML_CSS_JavaScript/images/image-7.png?raw=true)
```html
<!DOCTYPE html>

<!-- Demonstrates paragraphs -->

<html lang="en">
    <head>
        <title>paragraphs</title>
    </head>
    <body>
        <p>
            Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus convallis scelerisque quam, vel hendrerit lectus viverra eu. Praesent posuere eget lectus ut faucibus. Etiam eu velit laoreet, gravida lorem in, viverra est. Cras ut purus neque. In porttitor non lorem id lobortis. Mauris gravida metus libero, quis maximus dui porta at. Donec lacinia felis consectetur venenatis scelerisque. Nulla eu nisl sollicitudin, varius velit sit amet, vehicula erat. Curabitur sollicitudin felis sit amet orci mattis, a tempus nulla pulvinar. Aliquam erat volutpat.
        </p>
        <p>
            Mauris ut dui in eros semper hendrerit. Morbi vel elit mi. Sed sit amet ex non quam dignissim dignissim et vel arcu. Pellentesque eget elementum orci. Morbi ac cursus ex. Pellentesque quis turpis blandit orci dapibus semper sed non nunc. Nulla et dolor nec lacus finibus volutpat. Sed non lorem diam. Donec feugiat interdum interdum. Vivamus et justo in enim blandit fermentum vel at elit. Phasellus eu ante vitae ligula varius aliquet. Etiam id posuere nibh.
        </p>
        <p>
            Aenean venenatis convallis ante a rhoncus. Nullam in metus vel diam vehicula tincidunt. Donec lacinia metus sem, sit amet egestas elit blandit sit amet. Nunc egestas sem quis nisl mattis semper. Pellentesque ut magna congue lorem eleifend sodales. Donec tortor tortor, aliquam vitae mollis sed, interdum ut lectus. Mauris non purus quis ipsum lacinia tincidunt.
        </p>
        <p>
            Integer at justo lacinia libero blandit aliquam ut ut dui. Quisque tincidunt facilisis venenatis. Nullam dictum odio quis lorem luctus, vel malesuada dolor luctus. Aenean placerat faucibus enim a facilisis. Maecenas eleifend quis massa sed eleifend. Ut ultricies, dui ac vulputate hendrerit, ex metus iaculis diam, vitae fermentum libero dui et ante. Phasellus suscipit, arcu ut consequat sagittis, massa urna accumsan massa, eu aliquet nulla lorem vitae arcu. Pellentesque rutrum felis et metus porta semper. Nam ac consectetur mauris.
        </p>
        <p>
            Suspendisse rutrum vestibulum odio, sed venenatis purus condimentum sed. Morbi ornare tincidunt augue eu auctor. Vivamus sagittis ac lectus at aliquet. Nulla urna mauris, interdum non nibh in, vehicula porta enim. Donec et posuere sapien. Pellentesque ultrices scelerisque ipsum, vel fermentum nibh tincidunt et. Proin gravida porta ipsum nec scelerisque. Vestibulum fringilla erat at turpis laoreet, nec hendrerit nisi scelerisque.
        </p>
        <p>
            Sed quis malesuada mi. Nam id purus quis augue sagittis pharetra. Nulla facilisi. Maecenas vel fringilla ante. Cras tristique, arcu sit amet blandit auctor, urna elit ultricies lacus, a malesuada eros dui id massa. Aliquam sem odio, pretium vel cursus eget, scelerisque at urna. Vestibulum posuere a turpis consectetur consectetur. Cras consequat, risus quis tempor egestas, nulla ipsum ornare erat, nec accumsan nibh lorem nec risus. Integer at iaculis lacus. Integer congue nunc massa, quis molestie felis pellentesque vestibulum. Nulla odio tortor, aliquam nec quam in, ornare aliquet sapien.
        </p>
    </body>
</html>
```
* h1, h2, and h3 denote different levels of headings.
```html
<!DOCTYPE html>

<!-- Demonstrates headings (for chapters, sections, subsections, etc.) -->

<html lang="en">

    <head>
        <title>headings</title>
    </head>

    <body>

        <h1>One</h1>
        <p>
            Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus convallis scelerisque quam, vel hendrerit lectus viverra eu. Praesent posuere eget lectus ut faucibus. Etiam eu velit laoreet, gravida lorem in, viverra est. Cras ut purus neque. In porttitor non lorem id lobortis. Mauris gravida metus libero, quis maximus dui porta at. Donec lacinia felis consectetur venenatis scelerisque. Nulla eu nisl sollicitudin, varius velit sit amet, vehicula erat. Curabitur sollicitudin felis sit amet orci mattis, a tempus nulla pulvinar. Aliquam erat volutpat.
        </p>

        <h2>Two</h2>
        <p>
            Mauris ut dui in eros semper hendrerit. Morbi vel elit mi. Sed sit amet ex non quam dignissim dignissim et vel arcu. Pellentesque eget elementum orci. Morbi ac cursus ex. Pellentesque quis turpis blandit orci dapibus semper sed non nunc. Nulla et dolor nec lacus finibus volutpat. Sed non lorem diam. Donec feugiat interdum interdum. Vivamus et justo in enim blandit fermentum vel at elit. Phasellus eu ante vitae ligula varius aliquet. Etiam id posuere nibh.
        </p>

        <h3>Three</h3>
        <p>
            Aenean venenatis convallis ante a rhoncus. Nullam in metus vel diam vehicula tincidunt. Donec lacinia metus sem, sit amet egestas elit blandit sit amet. Nunc egestas sem quis nisl mattis semper. Pellentesque ut magna congue lorem eleifend sodales. Donec tortor tortor, aliquam vitae mollis sed, interdum ut lectus. Mauris non purus quis ipsum lacinia tincidunt.
        </p>

        <h4>Four</h4>
        <p>
            Integer at justo lacinia libero blandit aliquam ut ut dui. Quisque tincidunt facilisis venenatis. Nullam dictum odio quis lorem luctus, vel malesuada dolor luctus. Aenean placerat faucibus enim a facilisis. Maecenas eleifend quis massa sed eleifend. Ut ultricies, dui ac vulputate hendrerit, ex metus iaculis diam, vitae fermentum libero dui et ante. Phasellus suscipit, arcu ut consequat sagittis, massa urna accumsan massa, eu aliquet nulla lorem vitae arcu. Pellentesque rutrum felis et metus porta semper. Nam ac consectetur mauris.
        </p>

        <h5>Five</h5>
        <p>
            Suspendisse rutrum vestibulum odio, sed venenatis purus condimentum sed. Morbi ornare tincidunt augue eu auctor. Vivamus sagittis ac lectus at aliquet. Nulla urna mauris, interdum non nibh in, vehicula porta enim. Donec et posuere sapien. Pellentesque ultrices scelerisque ipsum, vel fermentum nibh tincidunt et. Proin gravida porta ipsum nec scelerisque. Vestibulum fringilla erat at turpis laoreet, nec hendrerit nisi scelerisque.
        </p>

        <h6>Six</h6>
        <p>
            Sed quis malesuada mi. Nam id purus quis augue sagittis pharetra. Nulla facilisi. Maecenas vel fringilla ante. Cras tristique, arcu sit amet blandit auctor, urna elit ultricies lacus, a malesuada eros dui id massa. Aliquam sem odio, pretium vel cursus eget, scelerisque at urna. Vestibulum posuere a turpis consectetur consectetur. Cras consequat, risus quis tempor egestas, nulla ipsum ornare erat, nec accumsan nibh lorem nec risus. Integer at iaculis lacus. Integer congue nunc massa, quis molestie felis pellentesque vestibulum. Nulla odio tortor, aliquam nec quam in, ornare aliquet sapien.
        </p>

    </body>

</html>
```
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_8_HTML_CSS_JavaScript/images/image-3.png?raw=true)
* We can also create unordered lists within HTML
```html
<!DOCTYPE html>

<!-- Demonstrates (ordered) lists -->

<html lang="en">
    <head>
        <title>list</title>
    </head>
    <body>
        <ul>
            <li>foo</li>
            <li>bar</li>
            <li>baz</li>
        </ul>
    </body>
</html>
```
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_8_HTML_CSS_JavaScript/images/image-4.png?raw=true)
* We can also create ordered lists within HTML
```html
<!DOCTYPE html>

<!-- Demonstrates (ordered) lists -->

<html lang="en">
    <head>
        <title>list</title>
    </head>
    <body>
        <ol>
            <li>foo</li>
            <li>bar</li>
            <li>baz</li>
        </ol>
    </body>
</html>
```
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_8_HTML_CSS_JavaScript/images/image-8.png?raw=true)
* We can also create a table in HTML
```html
<!DOCTYPE html>

<!-- Demonstrates table -->

<html lang="en">
    <head>
        <title>table</title>
    </head>
    <body>
        <table>
            <tr> <!-- table row -->
                <td>1</td> <!-- table data -->
                <td>2</td>
                <td>3</td>
            </tr>
            <tr>
                <td>4</td>
                <td>5</td>
                <td>6</td>
            </tr>
            <tr>
                <td>7</td>
                <td>8</td>
                <td>9</td>
            </tr>
            <tr>
                <td>*</td>
                <td>0</td>
                <td>#</td>
            </tr>
        </table>
    </body>
</html>
```
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_8_HTML_CSS_JavaScript/images/image-9.png?raw=true)
* Images can also be utilized within HTML
```html
<!DOCTYPE html>

<!-- Demonstrates image -->

<html lang="en">
    <head>
        <title>image</title>
    </head>
    <body>
        <!-- alt属性：提供替代图片的文本描述 -->
        <img alt="photo of bridge" src="bridge.png">
    </body>
</html>
```
* Videos can also be included in HTML:
```html
<!DOCTYPE html>

<!-- Demonstrates video -->

<html lang="en">
    <head>
        <title>video</title>
    </head>
    <body>
        <video controls muted> <!-- 默认静音 -->
            <source src="video.mp4" type="video/mp4">
        </video>
    </body>
</html>
```
* You can also link between various web pages
```html
<!DOCTYPE html>

<!-- Demonstrates link -->

<html lang="en">
    <head>
        <title>link</title>
    </head>
    <body>
       Visit <a href="https://www.harvard.edu">Harvard</a>.
    </body>
</html>
```
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_8_HTML_CSS_JavaScript/images/image-10.png?raw=true)
* Meta tags are used to hold information about the data within the HTML file.
* `<meta>` 标签用于定义网页的元数据（metadata），即关于网页本身的描述性信息。
```html
<!DOCTYPE html>

<!-- Demonstrates responsive design -->

<html lang="en">
    <head>
        <!-- this set of meta attributes makes this page mobile-friendly -->
        <meta name="viewport" content="initial-scale=1, width=device-width">
        <title>meta</title>
    </head>
    <body>
        Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus convallis scelerisque quam, vel hendrerit lectus viverra eu. Praesent posuere eget lectus ut faucibus. Etiam eu velit laoreet, gravida lorem in, viverra est. Cras ut purus neque. In porttitor non lorem id lobortis. Mauris gravida metus libero, quis maximus dui porta at. Donec lacinia felis consectetur venenatis scelerisque. Nulla eu nisl sollicitudin, varius velit sit amet, vehicula erat. Curabitur sollicitudin felis sit amet orci mattis, a tempus nulla pulvinar. Aliquam erat volutpat.
    </body>
</html>
```
* open graph(og)标签，用于定义网页在社交网络中分享时元数据的标准。通过这些标签，你可以控制网页在社交媒体平台上分享时的标题、描述和图片等信息。
```html
<!DOCTYPE html>

<!-- Demonstrates Open Graph tags -->

<html lang="en">
    <head>
        <!-- 定义网页在社交媒体上分享时的标题 -->
        <meta property="og:title" content="CS50">
        <!-- 定义网页在社交媒体上分享时的描述 -->
        <meta property="og:description" content="Introduction to the intellectual enterprises of computer science and the art of programming.">
        <!-- 定义网页在社交媒体上分享时的图片 -->
        <meta property="og:image" content="cat.jpg">
        <title>meta</title>
    </head>
    <body>
        ...
    </body>
</html>
```
* You can also create forms reminiscent of Google’s search
```html
<!DOCTYPE html>

<!-- Demonstrates additional form attributes -->

<html lang="en">
    <head>
        <title>search</title>
    </head>
    <body>
        <!-- action: here is where I want you to request after you click button -->
        <!-- method: which method should we use to actually access that route -->
        <!-- 点击button跳转到google搜索 -->
        <form action="https://www.google.com/search" method="get">
            <input autocomplete="off" autofocus name="q" placeholder="Query" type="search">
            <button>Google Search</button>
        </form>
    </body>
</html>
```
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_8_HTML_CSS_JavaScript/images/image-11.png?raw=true)
## Regular Expressions(正则表达式)
* Regular expressions or regexes are a means by which to ensure that user-provided data fits a specific format.
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_8_HTML_CSS_JavaScript/images/image-1.png?raw=true)
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_8_HTML_CSS_JavaScript/images/image-2.png?raw=true)
```html
<!DOCTYPE html>

<!-- Demonstrates pattern attribute -->

<html lang="en">
    <head>
        <title>register</title>
    </head>
    <body>
        <form>
            <!-- the pattern attribute is handed a regular expression to denote that the email address must include an @ symbol and a .edu. -->
            <input autocomplete="off" autofocus name="email" pattern=".+@.+\.edu" placeholder="Email" type="email">
            <!-- .+ means one or more characters -->
            <!-- \. means . -->
            <button>Register</button>
        </form>
    </body>
</html>
```
## CSS
* CSS, or cascading style sheet, is a markup language that allows you to fine-tune the aesthetics of your HTML files.（CSS，或称层叠样式表，是一种标记语言，它允许你对HTML文件的美观进行微调）
* CSS is filled with properties, which include key-value pairs.
```html
<!DOCTYPE html>

<!-- Removes outer DIV -->
<!-- <div> tags are used to divide up this HTML file into specific regions.-->

<html lang="en">
    <head>
        <title>css</title>
    </head>
    <body style="text-align: center">
        <div style="font-size: large">
            John Harvard
        </div>
        <div style="font-size: medium">
            Welcome to my home page!
        </div>
        <div style="font-size: small">
            Copyright &#169; John Harvard
        </div>
    </body>
</html>
```
```html
<!DOCTYPE html>

<!-- Uses semantic tags instead of DIVs -->

<html lang="en">
    <head>
        <title>css</title>
    </head>
    <body style="text-align: center">
        <header style="font-size: large">
            John Harvard
        </header>
        <main style="font-size: medium">
            Welcome to my home page!
        </main>
        <footer style="font-size: small">
            Copyright &#169; John Harvard
        </footer>
    </body>
</html>
```
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_8_HTML_CSS_JavaScript/images/image-12.png?raw=true)
```css
/* style.css */
.centered
{
    text-align: center;
}

.large
{
    font-size: large;
}

.medium
{
    font-size: medium;
}

.small
{
    font-size: small;
}
```
```html
<!DOCTYPE html>

<!-- Demonstrates external stylesheets -->

<html lang="en">
    <head>
        <!-- href: 指定外部资源的 URL或路径 -->
        <!-- rel: 指定当前文档与被链接文档之间的关系。stylesheet 表示链接的资源是一个样式表 -->
        <link href="style.css" rel="stylesheet">
        <title>css</title>
    </head>
    <body class="centered">
        <header class="large">
            John Harvard
        </header>
        <main class="medium">
            Welcome to my home page!
        </main>
        <footer class="small">
            Copyright &#169; John Harvard
        </footer>
    </body>
</html>
```
```html
<!DOCTYPE html>

<!-- Demonstrates link -->

<html lang="en">
    <head>
        <!-- #harvard定义了 ID 为 harvard 的元素的样式，将文本颜色设置为红色 -->
        <!-- a定义了所有<a>标签的样式，移除了默认的下划线 -->
        <!-- a:hover定义了鼠标悬停在<a>标签上时的样式，添加下划线 -->
        <style>

            #harvard
            {
                color: red;
            }

            #yale
            {
                color: blue;
            }

            a
            {
                text-decoration: none;
            }

            a:hover
            {
                text-decoration: underline;
            }
        </style>
        <title>link</title>
    </head>
    <body>
       Visit <a href="https://www.harvard.edu" id="harvard">Harvard</a> or <a href="https://www.yale.edu/" id="yale">Yale</a>.
    </body>
</html>
```
![alt text](https://github.com/lzt0911/CS50/blob/main/Lecture_8_HTML_CSS_JavaScript/images/image-13.png?raw=true)
## Frameworks
* Similar to third-party libraries we can leverage in Python, there are third-party libraries called frameworks that we can utilize with our HTML files.
* Bootstrap([Bootstrap Documentation](https://getbootstrap.com/docs/5.3/getting-started/introduction/)) is one of these frameworks that we can use to beautify our HTML and easily perfect design elements such that our pages are more readable.
```html
<head>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN" crossorigin="anonymous">
    <title>search</title>
</head>
```
## JavaScript
* JavaScript is another programming language that allows for interactivity within web pages.
```js
var x = 44; // 局部变量
var nums = [1, 2, 3, 4, 5];
var mixed = [1, true, 3.333, 'five'];
var herbie = {year: 1963, model: 'Beetle'};

for (var key in object)
{
    // 遍历一个对象的所有可枚举属性
    // 通常用于遍历对象的键（key），而不是值（value）
}
for (var key of object)
{
    // 于遍历可迭代对象（如数组、字符串、Map、Set等）的值
    // 不会遍历对象的键，而是直接遍历对象的值
}

var nums = [1, 2, 3, 4, 5];
nums = nums.map(function(num) {
    return num * 2;
}); // double every elements

```
* document object model(DOM)
  * DOM properties
    * innerHTML: Holds the HTML inside a set of HTML tags
    * nodeName: The name of an HTML element's attribute
    * id: The "id" attribute of an HTNL element
    * parentNode: A reference to the node one level up in the DOM
    * childNodes: An array of references to the nodes one level down in the DOM
    * attributes: An array of attributes of an HTML element
    * style: An object encapsulating the CSS/HTML styling of an element
  * DOM methods
    * getElementById(id)
    * getElementsByTagName(tag)
    * appendChild(node)
    * removeChild(node)
```html
<html>
    <head>
        <title>Event Handlers</title>
    </head>
    <body>
        <button onclick="alertName(event)">Button 1</button>
        <button onclick="alertName(event)">Button 2</button>
    </body>
    <script>
        function alertName(event)
        {
            var trigger = event.srcElement;
            alert('You clicked on ' + trigger.innerHTML);
        }
    </script>
</html>
```
```html
<!DOCTYPE html>

<!-- Demonstrates onsubmit -->
<!-- this form uses an onsubmit property to trigger a script found at the top of the file -->
<!-- The script uses alert to create an alert pop-up. -->
<!-- #name.value goes to the textbox on the page and obtains the value typed by the user. -->

<html lang="en">
    <head>
        <script>

            function greet()
            {
                alert('hello, ' + document.querySelector('#name').value);
            }

        </script>
        <title>hello</title>
    </head>
    <body>
        <!-- return false阻止表单的默认提交行为（即不刷新页面）-->
        <form onsubmit="greet(); return false;">
            <input autocomplete="off" autofocus id="name" placeholder="Name" type="text">
            <input type="submit">
        </form>
    </body>
</html>
```
```html
<!DOCTYPE html>

<!-- Demonstrates DOMContentLoaded -->
<!-- creates an addEventListener to listen to the form submit being triggered -->
<!-- DOMContentLoaded ensures that the whole page is loaded before executing the JavaScript. -->

<html lang="en">
    <head>
        <!-- preventDefault方法用于阻止事件的默认行为 -->
        <script>

            document.addEventListener('DOMContentLoaded', function() {
                document.querySelector('form').addEventListener('submit', function(e) {
                    alert('hello, ' + document.querySelector('#name').value);
                    e.preventDefault();
                });
            });

        </script>
        <title>hello</title>
    </head>
    <body>
        <form>
            <input autocomplete="off" autofocus id="name" placeholder="Name" type="text">
            <input type="submit">
        </form>
    </body>
</html>
```
```html
<!DOCTYPE html>

<!-- Demonstrates programmatic changes to style -->
<!--  JavaScript listens for when a specific button is clicked. Upon such a click, certain style attributes on the page are changed. body is defined as the body of the page. Then, an event listener waits for the clicking of one of the buttons. Then, the body.style.backgroundColor is changed. -->

<html lang="en">
    <head>
        <title>background</title>
    </head>
    <body>
        <button id="red">R</button>
        <button id="green">G</button>
        <button id="blue">B</button>
        <script>

            let body = document.querySelector('body');
            document.querySelector('#red').addEventListener('click', function() {
                body.style.backgroundColor = 'red';
            });
            document.querySelector('#green').addEventListener('click', function() {
                body.style.backgroundColor = 'green';
            });
            document.querySelector('#blue').addEventListener('click', function() {
                body.style.backgroundColor = 'blue';
            });

        </script>
    </body>
</html>
```
```html
<!DOCTYPE html>

<html lang="en">
    <head>
        <script>

            // Toggles visibility of greeting
            function blink()
            {
                let body = document.querySelector('body');
                if (body.style.visibility == 'hidden')
                {
                    body.style.visibility = 'visible';
                }
                else
                {
                    body.style.visibility = 'hidden';
                }
            }

            // Blink every 500ms
            window.setInterval(blink, 500);

        </script>
        <title>blink</title>
    </head>
    <body>
        hello, world
    </body>
</html>
```
```html
<!DOCTYPE html>
<!-- This is a JavaScript implementation of autocomplete. This pulls from a file (not pictured here) called large.js that is a list of words. -->

<html lang="en">

    <head>
        <title>autocomplete</title>
    </head>

    <body>

        <input autocomplete="off" autofocus placeholder="Query" type="text">

        <ul></ul>

        <script src="large.js"></script>
        <!-- keyup: 当用户在输入框中按下并释放键盘上的键时触发-->
        <script>

            let input = document.querySelector('input');
            input.addEventListener('keyup', function(event) {
                let html = '';
                if (input.value) {
                    for (word of WORDS) {
                        if (word.startsWith(input.value)) {
                            html += `<li>${word}</li>`;
                        }
                    }
                }
                document.querySelector('ul').innerHTML = html;
            });

        </script>

    </body>
</html>
```
```html
<!DOCTYPE html>

<!-- 获取地理位置 -->

<html lang="en">
    <head>
        <title>geolocation</title>
    </head>
    <body>
        <script>

            navigator.geolocation.getCurrentPosition(function(position) {
                document.write(position.coords.latitude + ", " + position.coords.longitude);
            });

        </script>
    </body>
</html>
```
```html
<!DOCTYPE html>

<html lang="en">
    <head>
        <link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@500&display=swap" rel="stylesheet">
        <link href="styles.css" rel="stylesheet">
        <title>Trivia!</title>
        <script>
            function correctClick(button) {
                button.style.backgroundColor = 'green';
                document.getElementById('result1').innerText = 'Correct!';
            }
            function incorrectClick(button) {
                button.style.backgroundColor = 'red';
                document.getElementById('result1').innerText = 'Incorrect';
            }
            function checkAnswer(button) {
                const input = document.getElementById('festival').value;
                if (input.toLowerCase() == "spring festival") {
                    button.style.backgroundColor = 'green';
                    document.getElementById('result2').innerText = 'Correct!';
                } else {
                    button.style.backgroundColor = 'red';
                    document.getElementById('result2').innerText = 'Incorrect';
                }
            }
        </script>
    </head>
    <body>
        <div class="header">
            <h1>Trivia!</h1>
        </div>

        <div class="container">
            <div class="section">
                <h2>Part 1: Multiple Choice </h2>
                <hr>
                <h3>How long is the annual holiday in China?</h3>
                <p id="result1"></p>
                <button type="submit", onclick="correctClick(this)">5 Days</button>
                <button type="submit", onclick="incorrectClick(this)">10 Days</button>
                <button type="submit", onclick="incorrectClick(this)">15 Days</button>
            </div>

            <div class="section">
                <h2>Part 2: Free Response</h2>
                <hr>
                <h3>Which festival has the longest holidays in China?</h3>
                <p id="result2"></p>
                <input type="text", placeholder="Festival", autocomplete="off" autofocus id="festival">
                <button type="submit", onclick="checkAnswer(this)">Check answer</button>
            </div>
        </div>
    </body>
</html>

```
```js
// 页面播放音频js

// 获取元素
const audio = document.getElementById('bg-music');
const musicIcon = document.querySelector('.music-icon');

// 初始化播放状态
let isPlaying = localStorage.getItem('musicPlaying') === 'true';

// 设置初始状态
if(isPlaying) {
    audio.play().catch(() => {
        // 处理自动播放被阻止的情况
        isPlaying = false;
        updateIcon();
    });
}
updateIcon();

// 切换播放状态
function toggleMusic() {
    isPlaying = !isPlaying;
    localStorage.setItem('musicPlaying', isPlaying);

    if(isPlaying) {
        audio.play();
    } else {
        audio.pause();
    }
    updateIcon();
}

// 更新按钮图标
function updateIcon() {
    musicIcon.classList.toggle('paused', !isPlaying);
}

// 绑定点击事件
document.getElementById('musicBtn').addEventListener('click', toggleMusic);

// 首次尝试自动播放（需要用户交互）
// 监听整个页面的点击事件，当用户首次点击页面任意位置时触发回调函数
// 当用户第一次点击页面时，检查isplaying状态，如果之前是播放状态，尝试播放音乐，立即移除事件监听器，避免重复触发
document.addEventListener('click', function initPlay() {
    if(isPlaying) audio.play();
    document.removeEventListener('click', initPlay);
});

```