---
title: CSS
mathjax: true
layout: default
toc: true
---

# CSS

```html
 <!DOCTYPE html>
<html>
<head>
    <title>Calculations Tool</title>
    <meta http-equiv="content-type" content="text/html; charset=utf-8" />
    <meta name="description" content="" />
    <meta name="keywords" content="" />
    <--! Cascading stylesheets included as a file --!>
    <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
    <link rel="stylesheet" href="css/calc-tool.css" />
    <--! Cascading stylesheets included inline--!>
    <style>
      body {background-color:lightgray}
      h1   {color:blue}
      p    {color:green}
    </style>
  </head>
  <body>
    <h1>This is a heading</h1>
    <p>This is a paragraph.</p>
  </body>
  </html>

```

# Links


```
a:link {
  color: blue;
  text-decoration: none;
}
 
a:visited {
  color: purple;
}
 
a:hover {
  text-decoration: underline;
}
 
a:active {
  color: red;
}
```


# Patterns

### Media Object 

an image on one side and a block of text beside it
```html
<div class="media">
<img class="media-image" src="shoes.png">
<div class="media-body">
<h4>Change it up</h4>
<p>
Don't run the same every time you hit the
road. Vary your pace, and vary the distance
of your runs.
</p>
</div>
</div>

```

### lobotomized owl

```html

* + * {
	margin-top: 1.5em;
}

```


### Label

```html
<p>
  <label for="password">Password</label>
  <input id="password" type="password" name="password"/>
</p>
```

### dropdown

```html
<nav>
  <div class="dropdown">
    <div class="dropdown-label">Main Menu</div>
    <div class="dropdown-menu"> 
      <ul class="submenu">
        <li><a href="/">Home</a></li>
        <li><a href="/coffees">Coffees</a></li>
        <li><a href="/brewers">Brewers</a></li>
        <li><a href="/specials">Specials</a></li>
        <li><a href="/about">About us</a></li>
      </ul>
    </div>
  </div>
</nav>
```


### Modal


```html

<button id="open"> Sign up </button>
 
 
<div class="modal" id="modal">
 
  <div class="modal-backdrop"></div>
  <div class="modal-body">
    <button class="modal-close" id="close">close</button>
 
    <h2> Wombat Newsletter</h2>
    <p> Sign up for our monthly newsletter. No spam.
        we promise </p>
 
     <p><button type="submit"> Submit </button> </p>
 
  </div>
 
 
 
</div>
 
 
 
<script>
 
  <script type="text/javascript">
 
    var button = document.getElementById('open');
    var close = document.getElementById('close');
    var modal = document.getElementById('modal');
 
    button.addEventListener('click, function (event) {
      event.preventDefault();
      modal.style.display = 'block';
    });
 
    close.addEventListener('click, function (event) {
      event.preventDefault();
      modal.style.display = 'none';
    });
  </script>
 
</script>



button {
  padding: 0.5em 0.7em;
  border: 1px solid #8d8d8d;
  background-color: white;
  font-size: 1em;
}
 
.modal {
  display: none;
}
 
.modal-backdrop {
  position: fixed;
  top: 0;
  right: 0;
  bottom: 0;
  left: 0;
  background-color: rgba(0, 0, 0, 0.5);
}
 
.modal-body {
  position: fixed;
  top: 3em;
  bottom: 3em;
  right: 20%;
  left: 20%;
  padding: 2em 3em;
  background-color: white;
  overflow: auto;
}
 
.modal-close {
  cursor: pointer;
}
```
