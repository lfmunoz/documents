---
title: HTML
mathjax: true
layout: default
toc: true
---

# HTML

HyperText Markup Language (HTML) is the main markup language for creating web pages and other information that can be displayed in a web browser.

```html
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8" />
<title>Smashing HTML5!</title>
 
<link rel="stylesheet" href="css/main.css" type="text/css" />
 
<!--[if IE]>
	<script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script><![endif]-->
<!--[if lte IE 7]>
	<script src="js/IE8.js" type="text/javascript"></script><![endif]-->
<!--[if lt IE 7]>
 
	<link rel="stylesheet" type="text/css" media="all" href="css/ie6.css"/><![endif]-->
</head>
 
<body id="index" class="home">
</body>
</html>
```

# Text

```html
<b> 	Defines bold text
<em> 	Defines emphasized text 
<i> 	Defines a part of text in an alternate voice or mood
<small> 	Defines smaller text
<strong> 	Defines important text
<sub> 	Defines subscripted text
<sup> 	Defines superscripted text
<ins> 	Defines inserted text
<del> 	Defines deleted text
```


# Forms

```html
<form name="input" action="html_form_action.asp" method="get">
    Username: <input type="text" name="user">
    <input type="submit" value="Submit">
</form> 


<form>
First name: <input type="text" name="firstname"><br>
Last name: <input type="text" name="lastname">
</form> 
```

```html
<code html>
<textarea rows="10" cols="30">
The cat was playing in the garden.
</textarea>

</code>
```

```html
<select name="cars">
<option value="volvo">Volvo</option>
<option value="saab">Saab</option>
<option value="fiat" selected>Fiat</option>
<option value="audi">Audi</option>
</select>
```

# Images

```html
<img src="images/github.png" alt="some_text">
<img src="images/doku.png" alt="some_text">
<img src="images/tux.png" alt="some_text">
<img src="images/wordpress.png" alt="some_text">
```

# Links

```html

<a href="url">Link text</a> 
<a href="http://www.w3schools.com/">Visit W3Schools</a> 
<a href="http://www.w3schools.com/" target="_blank">Visit W3Schools!</a> 
<A HREF="The URL of the site"><img src="The URL of the image"></A>
```


# Tables


```html
<table border="1">
    <tr>
        <td>row 1, column 1</td>
        <td>row 1, column 2</td>
    </tr>
    <tr>
        <td>row 2, column 1</td>
        <td>row 2, column 2</td>
    </tr>
</table>
```

# Canvas


```html
<head>
  <script>
    window.onload = function() {
      // we reference the canvas to draw, get it from the DOM
      var canvas = document.getElementById("tshirtcanvas");
      // we apparently need a "2d" context to draw
      var context = canvas.getContext("2d"); 
      // x ,y, width, height
      context.fillRect(10,10,100,100);
    };
  </script>
</head>
 
<body>
  <canvas id="tshirtCanvas" width="600" height="200">  <canvas>
</body>
```


# Learning

* https://www.gnu.org/software/bash/manual/bash.html