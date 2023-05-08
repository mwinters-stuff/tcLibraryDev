/*
    The code in this file uses open source libraries provided by thecoderscorner

    DO NOT EDIT THIS FILE, IT WILL BE GENERATED EVERY TIME YOU USE THE UI DESIGNER
    INSTEAD EITHER PUT CODE IN YOUR SKETCH OR CREATE ANOTHER SOURCE FILE.

    All the variables you may need access to are marked extern in this file for easy
    use elsewhere.
 */

#include <tcMenu.h>
#include "esp32s2Keyb_menu.h"
#include "../ThemeMonoBordered.h"

// Global variable declarations
const PROGMEM  ConnectorLocalInfo applicationInfo = { "ESP32-S2 Saola board", "b447b433-fe4f-4ce7-8746-d94bfeefc707" };
ArduinoEEPROMAbstraction glArduinoEeprom(&EEPROM);
EepromAuthenticatorManager authManager(4);
U8G2_SH1106_128X64_NONAME_F_HW_I2C gfx(U8G2_R0, U8X8_PIN_NONE, U8X8_PIN_NONE, U8X8_PIN_NONE);
U8g2Drawable gfxDrawable(&gfx, &Wire);
GraphicsDeviceRenderer renderer(30, applicationInfo.name, &gfxDrawable);

// Global Menu Item declarations
const PROGMEM AnyMenuInfo minfo78 = { "78", 25, 0xffff, 0, onSpeed78 };
ActionMenuItem menu78(&minfo78, nullptr, INFO_LOCATION_PGM);
const PROGMEM AnyMenuInfo minfo45 = { "45", 24, 0xffff, 0, onSpeed45 };
ActionMenuItem menu45(&minfo45, &menu78, INFO_LOCATION_PGM);
const PROGMEM AnyMenuInfo minfo33 = { "33", 23, 0xffff, 0, onSpeed33 };
ActionMenuItem menu33(&minfo33, &menu45, INFO_LOCATION_PGM);
const PROGMEM SubMenuInfo minfoSpeed = { "Speed", 22, 0xffff, 0, NO_CALLBACK };
BackMenuItem menuBackSpeed(&minfoSpeed, &menu33, INFO_LOCATION_PGM);
SubMenuItem menuSpeed(&minfoSpeed, &menuBackSpeed, nullptr, INFO_LOCATION_PGM);
const char enumStrFoods_0[] PROGMEM = "Pizza";
const char enumStrFoods_1[] PROGMEM = "Pasta";
const char enumStrFoods_2[] PROGMEM = "Salad";
const char enumStrFoods_3[] PROGMEM = "Pie";
const char* const enumStrFoods[] PROGMEM  = { enumStrFoods_0, enumStrFoods_1, enumStrFoods_2, enumStrFoods_3 };
const PROGMEM EnumMenuInfo minfoFoods = { "Foods", 4, 8, 3, NO_CALLBACK, enumStrFoods };
EnumMenuItem menuFoods(&minfoFoods, 0, &menuSpeed, INFO_LOCATION_PGM);
const PROGMEM AnalogMenuInfo minfoIntEdit = { "Int Edit", 1, 2, 100, NO_CALLBACK, 0, 1, "%" };
AnalogMenuItem menuIntEdit(&minfoIntEdit, 0, &menuFoods, INFO_LOCATION_PGM);
const PROGMEM BooleanMenuInfo minfoSelectMeNewBoolItem = { "New BoolItem", 21, 0xffff, 1, NO_CALLBACK, NAMING_CHECKBOX };
BooleanMenuItem menuSelectMeNewBoolItem(&minfoSelectMeNewBoolItem, true, nullptr, INFO_LOCATION_PGM);
const PROGMEM AnyMenuInfo minfoSelectMePressMe = { "Press Me", 9, 0xffff, 0, pressMeActionRun };
ActionMenuItem menuSelectMePressMe(&minfoSelectMePressMe, &menuSelectMeNewBoolItem, INFO_LOCATION_PGM);
const PROGMEM FloatMenuInfo minfoSelectMeFloat1 = { "Float 1", 7, 0xffff, 3, NO_CALLBACK };
FloatMenuItem menuSelectMeFloat1(&minfoSelectMeFloat1, 0.0, &menuSelectMePressMe, INFO_LOCATION_PGM);
const PROGMEM SubMenuInfo minfoSelectMe = { "Select Me", 6, 0xffff, 0, NO_CALLBACK };
BackMenuItem menuBackSelectMe(&minfoSelectMe, &menuSelectMeFloat1, INFO_LOCATION_PGM);
SubMenuItem menuSelectMe(&minfoSelectMe, &menuBackSelectMe, &menuIntEdit, INFO_LOCATION_PGM);
const PROGMEM AnyMenuInfo minfoExtrasDate = { "Date", 26, 0xffff, 0, NO_CALLBACK };
DateFormattedMenuItem menuExtrasDate(&minfoExtrasDate, DateStorage(1, 1, 2020), nullptr, INFO_LOCATION_PGM);
const PROGMEM AnyMenuInfo minfoExtrasMyList = { "My List", 13, 0xffff, 0, NO_CALLBACK };
ListRuntimeMenuItem menuExtrasMyList(&minfoExtrasMyList, 0, fnExtrasMyListRtCall, &menuExtrasDate, INFO_LOCATION_PGM);
const PROGMEM AnyMenuInfo minfoExtrasColor = { "Color", 12, 16, 0, NO_CALLBACK };
Rgb32MenuItem menuExtrasColor(&minfoExtrasColor, RgbColor32(0, 0, 0), false, &menuExtrasMyList, INFO_LOCATION_PGM);
const PROGMEM AnyMenuInfo minfoExtrasText = { "Text", 11, 11, 0, NO_CALLBACK };
TextMenuItem menuExtrasText(&minfoExtrasText, "", 5, &menuExtrasColor, INFO_LOCATION_PGM);
const PROGMEM SubMenuInfo minfoExtras = { "Extras", 10, 0xffff, 0, NO_CALLBACK };
BackMenuItem menuBackExtras(&minfoExtras, &menuExtrasText, INFO_LOCATION_PGM);
SubMenuItem menuExtras(&minfoExtras, &menuBackExtras, &menuSelectMe, INFO_LOCATION_PGM);

void setupMenu() {
    // First we set up eeprom and authentication (if needed).
    setSizeBasedEEPROMStorageEnabled(false);
    menuMgr.setEepromRef(&glArduinoEeprom);
    authManager.initialise(menuMgr.getEepromAbstraction(), 200);
    menuMgr.setAuthenticator(&authManager);
    // Code generated by plugins.
    gfx.begin();
    renderer.setUpdatesPerSecond(10);
    switches.init(internalDigitalIo(), SWITCHES_POLL_EVERYTHING, true);
    menuMgr.initFor4WayJoystick(&renderer, &menuExtras, 18, 20, 21, 19, -1, 20);
    renderer.setTitleMode(BaseGraphicalRenderer::NO_TITLE);
    renderer.setUseSliderForAnalog(false);
    installMonoBorderedTheme(renderer, MenuFontDef(nullptr, 1), MenuFontDef(nullptr, 1), true);
}

