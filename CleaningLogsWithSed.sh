sed -i -E \
  -e '/^#/d' \
  -e 's/HTTP\/1\.0/HTTP\/1.1/g' \
  -e 's/\b[0-9]{4}-?[0-9]{4}-?[0-9]{4}-?[0-9]{4}\b/XXXX-XXXX-XXXX-XXXX/g' \
  server_access.log