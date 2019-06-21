query = '''SELECT name, about, image, combinations.id_p
    FROM professions, combinations
    WHERE professions.id_p = combinations.id_p AND
    combinations.id_i = :id_i AND
    combinations.id_q = :id_q AND
    combinations.id_s = :id_s'''

next_item_query = '''SELECT name, about, image, professions.id_p FROM professions
                     WHERE professions.id_p = :id_p'''