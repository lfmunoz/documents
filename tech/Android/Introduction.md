---
title: Android
mathjax: true
layout: default
toc: true
---


# Android




## Icons

https://material.io/resources/icons/?icon=build_circle&style=baseline

```kotlin
import androidx.compose.material.icons.filled.PieChart
import androidx.compose.material.icons.filled.SentimentSatisfied
import androidx.compose.material.icons.filled.SentimentSatisfiedAlt
import androidx.compose.material.icons.filled.Settings
import androidx.compose.material.icons.rounded.Build

icon = Icons.Filled.SentimentSatisfiedAlt
icon = Icons.Filled.ExitToApp
icon = Icons.Rounded.Build,
icon = Icons.Filled.Settings,
```


# Android Jetpack Compose 


* Official Examples
    * https://github.com/android/compose-samples


https://developer.android.com/jetpack/androidx/explorer
https://developer.android.com/jetpack/androidx/releases/compose-material
SDK Versions
https://developer.android.com/guide/topics/manifest/uses-sdk-element
Edit



```kotlin
Column(
    modifier = Modifier.fillMaxWidth(),
    verticalArrangement = Arrangement.Top,
    horizontalAlignment = Alignment.End
) {
    Row {
        RallyTab(
            text = "Account",
            icon = Icons.Filled.Settings,
            onSelected = { onTabSelected(SorshaScreen.Account) },
            selected = true
        )

        RallyTab(
            text = "Axxxccount",
            icon = Icons.Filled.Settings,
            onSelected = { onTabSelected(SorshaScreen.Account) },
            selected = true
        )
    }
}

```



# Box Model


![Box Model](/documents/assets/css_boxes.png)



```kotlin
@Preview
@Composable
fun PaddingExample() {
    Text(
        text = "Hello World!",
        color = Color.White,
        modifier = Modifier
            .padding(8.dp) // margin
            .border(2.dp, Color.White) // outer border
            .padding(8.dp) // space between the borders
            .border(2.dp, Color.Green) // inner border
            .padding(8.dp) // padding
    )
}
```


https://stackoverflow.com/questions/62939473/how-to-add-margin-in-jetpack-compose


https://developer.android.com/jetpack/compose/layout#modifiers



https://developer.android.com/jetpack/androidx/releases/compose-ui#1.0.0-alpha09


https://developer.android.com/jetpack/androidx/versions/all-channel


# Publishing

Create a new developer account

* https://play.google.com/console/u/0/signup
*  You’ll need to pay a one-time registration fee of 25 dollars

