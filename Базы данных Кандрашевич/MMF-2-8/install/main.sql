--install
--this file is main to creat schema
--this file must be run under system user
-- 1 - username
-- 2 - location
-- example of run @main vanya C:\_programs\oradata\ORCL\tablespaces
DEFINE USER_NAME = &&1
DEFINE DATA_TBSP_LOCATION = &&2


SPOOL 'install\INSTALL.log'

@install\create_tablespaces.sql &&USER_NAME &&DATA_TBSP_LOCATION
PROMPT 'create_tablespaces was launched'

@install\create_user.sql &&USER_NAME
PROMPT 'create_user was launched'

@install\privilege_schema.sql &&USER_NAME
PROMPT 'privilege_schema was launched'

SPOOL OFF