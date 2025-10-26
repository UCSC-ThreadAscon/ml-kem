# https://esp32.com/viewtopic.php?t=42080
set(EXTRA_COMPONENT_DIRS "mlkem-native/mlkem")

idf_component_register(
  SRC_DIRS "mlkem-native/mlkem"
           "mlkem-native/mlkem/src"
  INCLUDE_DIRS "mlkem-native/mlkem"
               "mlkem-native/mlkem/src"
  PRIV_REQUIRES "utilities")