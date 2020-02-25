idf_component_register(SRCS	"crypto/tiny-AES-c/aes.c"
				"fido2/apdu.c"
				"crypto/cifra/src/blockwise.c"
				"fido2/crypto.c"
				"fido2/ctap.c"
				"fido2/ctaphid.c"
				"fido2/ctap_parse.c"
				"fido2/data_migration.c"
				"fido2/device.c"
				"fido2/log.c"
				"crypto/sha256/sha256.c"
				"crypto/cifra/src/sha512.c"
				"fido2/stubs.c"
				"fido2/test_power.c"
				"fido2/u2f.c"
				"crypto/micro-ecc/uECC.c"
				"fido2/util.c"
				"fido2/version.c"
				"fido2/extensions/extensions.c"
				"fido2/extensions/solo.c"
				"fido2/extensions/wallet.c"
				"esp32/device.c"
                    INCLUDE_DIRS fido2 fido2/extensions crypto/sha256 crypto/tiny-AES-c/ crypto/cifra/src crypto/cifra/src/ext crypto/micro-ecc esp32
                    REQUIRES cbor nvs_flash)

target_compile_definitions(${COMPONENT_LIB} PRIVATE "APP_CONFIG=\"app.h\"")
target_compile_definitions(${COMPONENT_LIB} PRIVATE "SOLO_VERSION_MAJ=3")
target_compile_definitions(${COMPONENT_LIB} PRIVATE "SOLO_VERSION_MIN=1")
target_compile_definitions(${COMPONENT_LIB} PRIVATE "SOLO_VERSION_PATCH=0")

