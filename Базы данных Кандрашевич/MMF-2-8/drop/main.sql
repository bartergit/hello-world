DEFINE USER_NAME = &&1

SPOOL 'drop\DROP_SCHEMA.log'

@drop\drop_tablespaces.sql &&USER_NAME
PROMPT 'drop_tablespaces launched'

@drop\drop_user.sql &&USER_NAME
PROMPT 'drop_user launched'

SPOOL OFF