DEFINE DATA_TBSP_NAME = &&1
DEFINE ADD1 = '_DATA'
DEFINE ADD2 = '_IDX'

DROP TABLESPACE &&DATA_TBSP_NAME&&ADD1
    INCLUDING CONTENTS AND DATAFILES
        CASCADE CONSTRAINTS; 
PROMPT 'TABLESPACE_DATA WAS DROPPED'

DROP TABLESPACE &&DATA_TBSP_NAME&&ADD2
    INCLUDING CONTENTS AND DATAFILES
        CASCADE CONSTRAINTS; 
PROMPT 'TABLESPACE_IDX WAS DROPPED'
