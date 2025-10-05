package main

/*
#include <stdlib.h>
*/
import (
	"C"
	"crypto/hmac"
	"crypto/sha256"
	"encoding/base64"
	"encoding/hex"
)

var (
	salt = []byte("Any+My+Secret+salt++")
	key  = []byte(base64.StdEncoding.EncodeToString([]byte("OwnKeyForLicense")))
)

//export getLicenseKey
func getLicenseKey() *C.char {
	cString := C.CString(getLicenseKeyByMachineGuid(GUID()))
	return cString
}

//export getCompGuid
func getCompGuid() *C.char {
	cString := C.CString(GUID())
	return cString
}

func getLicenseKeyByMachineGuid(machineGuid string) string {
	compKey := base64.StdEncoding.EncodeToString([]byte(machineGuid))
	hash := hmac.New(sha256.New, key)
	hash.Write([]byte(compKey))
	signature := hash.Sum(salt)
	return hex.EncodeToString(signature)
}
