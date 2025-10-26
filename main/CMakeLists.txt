macro(start_delimiter)

    message("---------------------------------------------------------------------------------")
    message("")

endmacro(start_delimiter)

macro(end_delimiter)

    message("")
    message("---------------------------------------------------------------------------------")

endmacro(end_delimiter)

idf_component_register(SRC_DIRS "src"
                       INCLUDE_DIRS "include"
                       PRIV_REQUIRES "mlkem_native" "coap_workload" "utilities"
                                     "nvs_flash" "openthread")