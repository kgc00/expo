---
title: Using react-native-vector-icons
---

`react-native-vector-icons` is a popular library for adding vector icons into your app. This library bundles many SVG icon sets, such as [FontAwesome](https://fontawesome.com/), to help you get started quicker. This guide will help you setup your project to use `react-native-vector-icons` and show you how to import icons into your react-native components.

## Setup

### iOS

We'll be using CocoaPods to install `react-native-vector-icons`. CocoaPods is a dependency manager for Swift and Objective-C, like NPM is for node. Check the [react-native-vector-icons docs](https://github.com/oblador/react-native-vector-icons#installation) for other approaches on setup for iOS.

1.) Install `react-native-vector-icons` into your xcode project.

Add the following line to your `./ios/Podfile`:

```ruby
target 'MyApp' do
  pod 'RNVectorIcons', :path => '../node_modules/react-native-vector-icons'  # add this line
```

Enter the ios directory and run pod update:

```sh
cd ./ios && npx pod update
```

2.) Include icon libraries with your app.

If you'll only be using one, such as FontAwesome, feel free to only add that item. Add the following to the `<dict>` inside your `./ios/<project-name>/info.plist`:

```xml
<key>UIAppFonts</key>
<array>
  <string>AntDesign.ttf</string> # optionally, only include icon sets you'd like to use
  <string>Entypo.ttf</string>
  <string>EvilIcons.ttf</string>
  <string>Feather.ttf</string>
  <string>FontAwesome.ttf</string>
  <string>FontAwesome5_Brands.ttf</string>
  <string>FontAwesome5_Regular.ttf</string>
  <string>FontAwesome5_Solid.ttf</string>
  <string>Foundation.ttf</string>
  <string>Ionicons.ttf</string>
  <string>MaterialIcons.ttf</string>
  <string>MaterialCommunityIcons.ttf</string>
  <string>SimpleLineIcons.ttf</string>
  <string>Octicons.ttf</string>
  <string>Zocial.ttf</string>
  <string>Fontisto.ttf</string>
</array>
```

### Android

Add the following to `android/app/build.gradle` ( NOT android/build.gradle ). Adding this to the end of the file is fine:

```java
apply from: "../../node_modules/react-native-vector-icons/fonts.gradle"
```

This line tells android studio's `gradle` to include the icon sets you'll be using, similar to step 2 in the iOS setup. If you'd like to only include some icon sets, like FontAwesome and EvilIcons, add this instead:

```java
project.ext.vectoricons = [
    iconFontNames: [ 'FontAwesome.ttf', 'EvilIcons.ttf' ] // Names of the font files you want to copy
]

apply from: "../../node_modules/react-native-vector-icons/fonts.gradle"
```

## Usage

Now that you’ve added `react-native-vector-icons` and some icon sets to your project, it's time to use them inside your react-native app. You can only import icons from libraries you included in the setup step, so make sure to include an icon set if you plan on using it.

Imports use the following syntax:

```js
import Something from 'react-native-vector-icons/IconLibraryName';
```

Importing and using two FontAwesome icons:

```js
import React from 'react';
import {SafeAreaView} from 'react-native';

// import icons from the FontAwesome library
import Icon from "react-native-vector-icons/FontAwesome";

// specify the icon you'd like with the name prop
const StarIcon = () => <Icon name="star" size={30} color="#900" />;
const RocketIcon = () => <Icon name="rocket" size={30} color="#900" />;

const App = () => {
  return (
    <SafeAreaView >
      <StarIcon />
      <RocketIcon />
    </SafeAreaView>
}
```

Importing and using and EvilIcon icon:

```js
import React from 'react';
import {SafeAreaView} from 'react-native';

// import icons from the EvilIcons library
import Icon from "react-native-vector-icons/EvilIcons";

const StarIcon = () => <Icon name="star" size={30} color="#900" />;

const App = () => {
  return (
    <SafeAreaView >
      <StarIcon />
    </SafeAreaView>
}
```

Importing two different libraries in the same file:

```js
import React from 'react';
import {SafeAreaView} from 'react-native';

import EvilIcon from "react-native-vector-icons/EvilIcons";
import FAIcon from "react-native-vector-icons/FontAwesome";

const StarIcon = () => <EvilIcon name="star" size={30} color="#900" />;
const RocketIcon = () => <FAIcon name="rocket" size={30} color="#900" />;

const App = () => {
  return (
    <SafeAreaView >
      <RocketIcon />
      <StarIcon />
    </SafeAreaView>
}
```

Using the import directly:

```js
import React from 'react';
import {SafeAreaView} from 'react-native';

import Icon from "react-native-vector-icons/FontAwesome";

const App = () => {
  return (
    <SafeAreaView >
      <Icon name="rocket" size={30} color="#900" />
    </SafeAreaView>
}
```

You can find the different icon and library names [here](https://github.com/oblador/react-native-vector-icons/tree/master/glyphmaps).
