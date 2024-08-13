# Google Navigation SDK for iOS

This pod contains the Google Navigation SDK for iOS, supporting both Objective-C and
Swift.

Use the [Google Navigation SDK for iOS](https://developers.google.com/maps/documentation/navigation/ios-sdk)
to build a turn-by-turn navigation experience into your mobile app.

Features Included:
* Customize the user interface with branding, custom controls, and time-sensitive trip information.
* Leverage the power of Google Maps to provide realtime navigation with voice guidance.
* Make it easy for customers to book a ride or order for delivery, keeping them informed with live progress.
* Optimize driver allocation and help drivers navigate on fast, reliable routes.

# Installation
1. Navigation SDK is currently available only to select customers. [Contact sales](https://cloud.google.com/contact-maps) to learn more.

1. Before you can use the Google Navigation SDK for iOS, follow these [setup instructions](https://developers.google.com/maps/documentation/ios-sdk/cloud-setup) to set up a project and get an API key. You will need to add the API key to your code in order to build your app with the Navigation SDK for iOS.

1. To integrate Google Navigation SDK for iOS into your Xcode project using CocoaPods,
specify it in your `Podfile`, for example:

    ```
    source 'https://github.com/CocoaPods/Specs.git'
    platform :ios, '15.0'
    target 'YOUR_APPLICATION_TARGET_NAME_HERE' do
      pod 'GoogleNavigation', '4.4.0'
    end
    ```

    Then, run the following command:

    ```
    $ pod install
    ```

1. Follow additional steps in the ["Set up an Xcode project"](https://developers.google.com/maps/documentation/navigation/ios-sdk/config) guide to add your API key to your project, import classes, and add a map.

# Resources

*   *Guides*: Read the [documentation](https://developers.google.com/maps/documentation/navigation/ios-sdk) for full use of the SDK.
*   *Code samples*: In order to try out our demo app, use:

    ```
    $ pod try GoogleNavigation
    ```

*   *Support*: Ask the community or get help from Google using the links on the Navigation SDK for iOS [support page](https://developers.google.com/maps/documentation/navigation/ios-sdk/support).

# License and Terms of Service

By using the Google Navigation SDK for iOS you accept Google's Terms of Service and
Policies. Pay attention particularly to the following aspects:

*   Depending on your app and use case, you may be required to display
    attribution. Read more about [attribution requirements](https://developers.google.com/maps/documentation/navigation/ios-sdk/policies).
*   The [Terms of Service](https://developers.google.com/maps/terms) are a
    comprehensive description of the legal contract that you enter with Google
    by using the Google Navigation SDK for iOS.
