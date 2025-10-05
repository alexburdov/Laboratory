set CGO_ENABLED=1
go build -o ../out/LicenseServiceLibrary.dll -buildmode=c-shared ./
go build -o ../out/LicenseService.exe 