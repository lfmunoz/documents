---
title: Organization and Structure of Applications
layout: default
---


In programming there is a guideline that says  

 > Group together items that are likely to change together

Yet most software systems simply ignores this and lure us into having a structure organized by category. If you look at the filesystem of the Linux Operating System you see the following:

```
/etc
/var/log
/bin  
/usr 
/lib 
/home/luis
/root
/dev 
```
Here you have _/var/log_ whose purpose is to hold the logs of every application on the system. It would be better if it was 

```
app/http/config
app/http/logs
app/home/root
app/home/luis
system/bin
system/lib
```

The problem being that an application is spread out. Ideally if I was going to remove an application I should be able to remove a single directory. Also if I am working with an application I shouldn't have to navigate across the entire filesystem to modify the configuration and then go look at the logs. Microsoft Windows almost got it right, they have a folder called Program Files:

```
Program Files/Steam
Program Files/Visual Basic
```

If I delete  _Program Files/Steam_ most of the application will be gone. Unfortunately there are shared library files that might remain, a System Registry that holds information about an application even after it has been uninstalled and Menu shortcuts.  These are artifacts of poor design, there is no reason the system couldn't keep track of all application information within one folder.

These days if feels wrong to install an application on my Linux Desktop. I feel like it will pollute it. If there
is a docker image I rather run that. Docker keeps applications contained and organized. If I want to remove
an application I can simply remove the image. If you use the package manager the chances that your system will returns to the exact state after uninstalling  an application is near zero. 

When I was studying government in High School, we were learning how laws get passed I thought it was strange that each year new laws get passed because how can that be sustaintable? If each year there are more regulations, more laws to comply with, wouldn't there be a point where the complexity is just too large and the whole system would collapse?

I mention this because this is how systems are today, each time you install a program if the system cannot guanratee it will completely remove an application without pollution then the system is not sustainable.  I find myself having to completely reinstall my Operating System everything 1-3 years in part because of pollution.

Android, interestingly, has a per-app subdirectory simply out of necessity of how its security works. Each application can only write to one folder, this is good for security but also makes it so all the data for an application can easily be removed. 


Next, looking at a typtical Java application structure you will often see:

```
/repository/UserRepository.java
/repository/BookRepository.java
/service/UserService.java
/service/BookService.java
/config/BookConfig.java
/config/UserConfig.java
/domain/UserEntity.java
/domain/BookEntity.java
/web/userApi.java
/web/BookApi.java
```
For example  [Jhipster](https://www.jhipster.tech/) follows this.  That layout comes from a misapplication of the popular book _Domain-Driven Design_ by Eric Evans it says: "Partition a complex program into LAYERS. Develop a design within each LAYER that is cohesive and that depends only on the layers below."  Then it describes two common layers: 

_Repository:_  The purpose of which is to encapsulate all the logic needed to obtain object references.  Repository acts as a storage place for globally accessible objects. 

_Services:_ There are some actions in the domain, some verbs, which do not seem to belong to any object. Adding such behavior to an object would spoil the object, making it stand for functionality which does not belong to it. When such a behavior is recognized in the domain, the best practice is to declare it as a Service.

None of this indicates you should layout the application with a folder per layer, yet that is what you see in many applications. In my experience this is not efficient. It would better if the layout was: 
  
```
components/user/UserRepository.java
components/user/UserService.java
components/user/UserApi.java
components/book/BookRepository.java
components/book/BookService.java
components/book/BookApi.java
```

If I change the repository from _PostgresQL_ to _MySQL_ it is unlikely I will change _BookRepository_ because 
that code communicates through an interface that won't change even if the database changes. If I am making changes to Book it is likely that _BookService_, _BookRepository_ and _BookApi_ will have to change. It doesn't make sense to spread out the code for Book.

 In front-end applications we are starting to see a component folder. A component will include CSS, HTML, and JavaScript in a single file.  This is closer to how I layout my applications.
  
 ```
 # Default Vue.js Layout
  src
├── App.vue
├── assets
│   └── logo.png
├── components
│   └── HelloWorld.vue
└── main.js
```
  
Front-end technology moves faster than back-end so I see this as an indication that these developers are understanding the benefits of keeping similiar code together.  I hope to see more back-end code following the principle because it is easier to read and work with. You often can tell a layout is problematic by how many files you have to open to implement a feature or fix. Also by how difficult it is to find sections of code after you haven't worked on them for a while.
 
 
 
 
 
 
 
 
 
 
 
 


